#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define GREY    "\033[1;30m"
#define RESET   "\033[0m"

#define WORD_LENGTH 5
#define MAX_TRIES 6
#define WORD_LIST_FILE "wordlist2.txt"
#define MAX_WORDS 10000

bool isin(char c, char *str) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (str[i] == c)
            return true;
    }
    return false;
}

char get_color(char guess, int idx, char *correct) {
    if (guess == correct[idx])
        return 'G';
    else if (isin(guess, correct))
        return 'Y';
    else
        return 'B';
}

void print_colored(char *guess, char *correct) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        char color = get_color(guess[i], i, correct);
        if (color == 'G')
            printf(GREEN "%c" RESET, guess[i]);
        else if (color == 'Y')
            printf(YELLOW "%c" RESET, guess[i]);
        else
            printf(GREY "%c" RESET, guess[i]);
    }
    printf("\n");
}

bool check_win(char *guess, char *correct) {
    return strncmp(guess, correct, WORD_LENGTH) == 0;
}

int load_words(char words[][WORD_LENGTH + 1]) {
    FILE *file = fopen(WORD_LIST_FILE, "r");
    if (!file) {
        perror("Unable to open word list");
        exit(1);
    }

    int count = 0;
    while (fgets(words[count], WORD_LENGTH + 2, file)) {
        words[count][strcspn(words[count], "\n")] = '\0';  // Remove newline
        if (strlen(words[count]) == WORD_LENGTH)
            count++;
        if (count >= MAX_WORDS)
            break;
    }

    fclose(file);
    return count;
}

bool is_in_list(char *guess, char words[][WORD_LENGTH + 1], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(guess, words[i]) == 0)
            return true;
    }
    return false;
}

int main() {
    srand(time(NULL));
    char words[MAX_WORDS][WORD_LENGTH + 1];
    int word_count = load_words(words);
    char correct[WORD_LENGTH + 1];
    strcpy(correct, words[rand() % word_count]);

    char guess[WORD_LENGTH + 2];  // +2 for newline and null
    printf("Welcome to Wordle in C! Guess the %d-letter word.\n", WORD_LENGTH);
    printf("You have %d tries.\n\n", MAX_TRIES);

    for (int tries = 1; tries <= MAX_TRIES; tries++) {
        printf("Try %d/%d: ", tries, MAX_TRIES);
        fgets(guess, sizeof(guess), stdin);
        guess[strcspn(guess, "\n")] = 0; // Remove newline

        if (strlen(guess) != WORD_LENGTH) {
            printf("Word must be %d letters long.\n", WORD_LENGTH);
            tries--;
            continue;
        }

        if (!is_in_list(guess, words, word_count)) {
            printf("Not in word list!\n");
            tries--;
            continue;
        }

        print_colored(guess, correct);

        if (check_win(guess, correct)) {
            printf(GREEN "\nYou won in %d tries!\n" RESET, tries);
            return 0;
        }
    }

    printf("\nThe correct word was: %s\n", correct);
    printf("Better luck next time!\n");

    return 0;
}
