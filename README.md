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

