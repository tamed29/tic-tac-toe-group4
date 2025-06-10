<h1 align="center">🎮 Advanced Tic-Tac-Toe Game (C++ Console Application) 🎮</h1>
<h2 align="center"> done by G2 software sec-A group-4 students </h2>
<p align="center">
  A feature-rich, colorized C++ console implementation of the classic Tic-Tac-Toe game supporting Single Player (Easy/Hard AI) and Two Player modes.
</p>

---

## 📌 Overview

This project is a terminal-based Tic-Tac-Toe game designed with interactive visuals, 
AI opponent functionality (including Minimax algorithm), and a friendly user interface. 
It serves as both an enjoyable game and a practical example of implementing game logic, 
user interaction, and artificial intelligence in C++.

---
## 🎯 Features

### 🎮 Game Modes
- **Single Player vs AI**
  - **Easy Mode**: Random AI moves.
  - **Hard Mode**: AI powered by the Minimax algorithm with alpha-beta pruning.
- **Two Player Mode**: Classic mode for local multiplayer games.

### 🧠 AI Implementation
- **Random AI**: Selects any available cell randomly.
- **Smart AI (Minimax)**:
  - Uses recursion with pruning to optimize decisions.
  - Considers all game outcomes for optimal strategy.

### 🖥️ Interface and UX
- **ASCII Board Display**: Easy-to-read grid with position hints (1–9).
- **Colorized Output**:
  - `X` – Red
  - `O` – Blue
  - Grid and titles – Green
- **Loading Animation**: Animated loading bar when the game starts.
- **Game Description**: In-game help menu explaining the rules.

### 🧪 Input Handling
- Full input validation: prevents invalid or duplicate moves.
- Error-resistant input loop for smooth experience.

---

## 🏁 How to Play

### 🎲 Controls
- Players select a grid position by entering numbers 1 through 9.
- Positions are mapped as:

1 | 2 | 3
---+---+---
4 | 5 | 6
---+---+---
7 | 8 | 9


### 📋 Rules
- First player uses **X**, second (or AI) uses **O**.
- The first to align 3 marks in a row (horizontal, vertical, or diagonal) wins.
- If all cells are filled without a winner, the game ends in a draw.
  ---

## 🛠️ How to Compile & Run

1. **Clone or Download the Repository**

2. **Compile**
   Use a C++ compiler like `g++`:
   ```bash
   g++ -std=c++11 -o tictactoe main.cpp
   RUN 
3. ./tictactoe
📷 Screenshots (Optional - Add your own)
If desired, create a /screenshots folder and showcase:

. Main Menu

. AI vs Player

. Two Player Gameplay

. Victory & Draw Messages

🔍 Educational Highlights
Demonstrates OOP principles in C++

. Implements classic Minimax with alpha-beta pruning

. Uses ANSI escape codes for colored CLI output

. Teaches clean game state management
---

## 🏫 Project Use Case

Ideal for:

* C++ learning and practice
* DSA/AI course projects
* Console UI/UX prototyping
---

## 🧑‍🎓 Academic Project Info

- **University**: Arba Minch University (AMU)
- **Course**: Data Structures and Algorithms
- **Project**: Tic-Tac-Toe Console Game in C++
- **Supervised By**: [Add instructor/supervisor name if available]

### 👥 Group Members with their girhub 

| Name             | GitHub Username   |
|------------------|-------------------|
| Tamirat Dereje   | [@tamed29](https://github.com/tamed29)       |
| Fuad Kedir       | [@furoyal7](https://github.com/furoyal7)     |
| Pineal Tadesse   | [@Pomi-7](https://github.com/Pomi-7)         |
| Beniyas Dawit    | [@Benas12-dv](https://github.com/Benas12-dv) |
| Ahmed Hussen     | [@Ahmeddin](https://github.com/Ahmeddin)     |
| Yohannis Dereje  | [@Yohannis-10](https://github.com/Yohannis-10) |

---

## 🔄 Changelog

| Version | Date       | Description                                 |
|---------|------------|---------------------------------------------|
| 1.0     | 2025-06-10 | Initial release with single/multiplayer mode and AI |
| 1.1     | TBD        | UI improvements and bug fixes               |
| 1.2     | TBD        | Efficiency stats for AI moves (planned)     |

---

## 💡 Future Enhancements (Suggestions)

- Add scoring system with persistent leaderboard.
- Expand board size to 4x4 or 5x5 with dynamic win conditions.
- Add sound feedback using OS-level features (optional).
- Graphical interface (using libraries like SFML or SDL).
- Enable online multiplayer mode.

## 🐞 Known Issues

- The game currently accepts only numeric input from 1 to 9; string handling may throw errors if improperly entered.
- There is no save/load functionality for game sessions.
- AI does not learn from past games — it restarts with a clean state each time.


## 💬 Feedback & Contributions

While this project is primarily for academic use, feedback, issues, and contributions are welcome to improve the codebase and usability. You may fork or build upon it for further experimentation.

---

## 📄 License

This project is intended for educational and personal use only. Feel free to modify and share with attribution.
also give us your feedback!!

Absolutely! Here's the **7th part** of your `README.md` file as **plain text**—a summary section including the key features and purpose of the project:

---

## 🧾 Summary of Tic-Tac-Toe C++ Project

This **Tic-Tac-Toe Console Application** is a comprehensive mini-project developed by students of **Arba Minch University** for the **Data Structures and Algorithms** course. The project blends interactive design, clean coding, and artificial intelligence, providing both educational value and enjoyable gameplay.

---

### 🔑 Key Features Recap

* 🎮 **Multiple Game Modes**: Choose between Single Player (with difficulty levels) and Two Player.
* 🧠 **AI Difficulty Levels**: From Random AI (Easy) to Minimax-based Smart AI (Hard).
* 🎨 **User Interface**: ASCII-based grid, color-coded outputs, and loading animations.
* ✅ **Robust Input Handling**: Prevents invalid, non-numeric, or repeated inputs.
* 🏆 **Win Detection**: All row, column, and diagonal scenarios checked per move.
* 🏗️ **Clean OOP Design**: C++ classes used for separation of game logic and display.
* ⚡ **Performance AI**: Minimax algorithm with alpha-beta pruning for faster decisions.

---

### 📚 Why This Project Stands Out

* Integrates **core DSA concepts** (recursion, backtracking, input validation).
* Demonstrates **real-world implementation** of AI logic in games.
* Designed to be **easily extendable** and **user-friendly** for non-technical users.

> This README was collaboratively built in parts by each team member to reflect equal contribution and shared understanding of the project goals.

🎉 **Thank you for reviewing our work!**

---





