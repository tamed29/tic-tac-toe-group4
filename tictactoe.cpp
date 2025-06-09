#include <iostream>
#include <vector>
#include <limits>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

// ANSI color codes for colorful terminal output
namespace Colors {

    const string RED = "\033[31m";
    const string BLUE = "\033[34m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string RESET = "\033[0m";
}

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    bool vsAI;
    bool hardMode;

    // ===== Part 1: Setup and Board Display =====

    void clearScreen();               // Clears the console screen
    void initializeBoard();           // Initializes a 3x3 game board
    void displayBoard() const;        // Draws the board with colors and numbers

    // ===== Part 2: Game Logic =====

    bool checkWin(char player) const; // Returns true if the player wins
    bool isBoardFull() const;         // Returns true if board is full (draw)
    void switchPlayer();              // Changes current player from X to O or vice versa

    // ===== Part 3: Input Handling =====

    void getPlayerMove();             // Gets and validates player input (1-9)

    // ===== Part 4: AI Logic =====

    void makeRandomAIMove();          // Random move for easy mode AI
    int minimax(int depth, bool isMaximizing, int alpha, int beta); // Minimax for hard AI
    void makeSmartAIMove();           // Smart AI move using minimax

    // ===== Part 5: UI and Flow =====

    void showLoadingScreen();         // Shows a fake loading bar
    void showGameDescription();       // Displays how to play

public:
    // ===== Constructor =====
    TicTacToe();                      // Initializes variables, seeds RNG

    // ===== Game Modes =====
    void playSinglePlayer();          // One player vs AI
    void playMultiPlayer();           // Two player mode

    // ===== Menu and Main Loop =====
    void showMainMenu();              // Displays main menu and routes user
};

// ===== Part 6: Main Function =====

int main() {
    TicTacToe game;
    game.showMainMenu();              // Starts the game
    return 0;
}
