<h1 align="center">🎮 Advanced Tic-Tac-Toe Game (C++ Console Application) 🎮</h1>

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

