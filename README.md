# 🟩 Wordle in C

A terminal-based clone of the popular word-guessing game **Wordle**, written in C.

---

## 🎮 Game Description

**Wordle** is a game where you try to guess a hidden 5-letter word within 6 attempts.

After each guess, the game gives color-coded feedback:
- 🟩 **Green**: Letter is correct and in the correct position
- 🟨 **Yellow**: Letter is in the word but in the wrong position
- ⬛ **Grey**: Letter is not in the word at all

The goal is to guess the secret word using logic and deduction.

---

## 🧠 Features

- Random 5-letter word selected from a file (`words.txt`)
- 6 guesses per game
- Colorful terminal output using ANSI codes
- Input validation and word list checking
- Written in pure C

---

## 🛠 Build & Run

### 1. Clone the repository (or copy the files)

Make sure you have:
- `wordle.c` – main game source code
- `words.txt` – list of 5-letter words, one per line

Example `words.txt`: snowy

✅ To Do / Ideas
Add support for Ukrainian or other languages

Use ncurses for a graphical UI

Show letter history / virtual keyboard

Score tracking or leaderboard


Let me know if you'd like me to generate this file as a downloadable `.md` or add GitHub badges, language options, etc.

Compiling of the game: ./wordle
