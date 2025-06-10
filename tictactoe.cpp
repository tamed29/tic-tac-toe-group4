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

// Clear the terminal screen
    void clearScreen() {
        cout << "\033[2J\033[1;1H";  // ANSI escape codes
    }

    // Initialize the game board
    void initializeBoard() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
    }

    // Display the current game board
    void displayBoard() const {
     //   clearScreen();
        cout << Colors::GREEN << "\n          TIC-TAC-TOE\n";
        cout << "          -----------\n";

        for (int i = 0; i < 3; i++) {
            cout << "          ";
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    cout << Colors::RED << " " << board[i][j] << " ";
                } else if (board[i][j] == 'O') {
                    cout << Colors::BLUE << " " << board[i][j] << " ";
                } else {
                    cout << " " << (i * 3 + j + 1) << " ";  // Show position numbers
                }

                if (j < 2) cout << Colors::GREEN << "|";
            }
            cout << Colors::RESET << endl;

            if (i < 2) {
                cout << Colors::GREEN << "          ---+---+---" << Colors::RESET << endl;
            }
        }
        cout << endl;
    }


    // ===== Part 2: Game Logic =====


    // Check if a player has won
    bool checkWin(char player) const {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
                return true;
            }
        }

        // Check diagonals
        return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
               (board[0][2] == player && board[1][1] == player && board[2][0] == player);
    }

    // Check if the board is full
    bool isBoardFull() const {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }

    // Switch players
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }


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
