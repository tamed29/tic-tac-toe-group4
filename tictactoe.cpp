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

        //Check diagonals
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
    // Get player move from input

    void getPlayerMove() {
        int move;
        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (cin.fail() || move < 1 || move > 9) {
                cout << Colors::RED << "Invalid input. Please enter a number between 1 and 9.\n" << Colors::RESET;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (board[row][col] != ' ') {
                cout << Colors::RED << "That position is already taken! Try again.\n" << Colors::RESET;
            } else {
                board[row][col] = currentPlayer;
                break;
            }
        }
    }

    // ===== Part 4: AI Logic =====

   // Simple AI that makes random moves
    void makeRandomAIMove() {
        vector<pair<int, int>> availableMoves;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    availableMoves.emplace_back(i, j);
                }
            }
        }

        if (!availableMoves.empty()) {
            int randomIndex = rand() % availableMoves.size();
            auto move = availableMoves[randomIndex];
            board[move.first][move.second] = currentPlayer;
        }
    }

    // Minimax algorithm with alpha-beta pruning for hard AI
    int minimax(int depth, bool isMaximizing, int alpha, int beta) {
        if (checkWin('O')) return 10 - depth;
        if (checkWin('X')) return depth - 10;
        if (isBoardFull()) return 0;

        if (isMaximizing) {
            int bestScore = -1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        board[i][j] = 'O';
                        int score = minimax(depth + 1, false, alpha, beta);
                        board[i][j] = ' ';
                        bestScore = max(score, bestScore);
                        alpha = max(alpha, bestScore);
                        if (beta <= alpha) break;
                    }
                }
            }
            return bestScore;
        }  else {
            int bestScore = 1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        board[i][j] = 'X';
                        int score = minimax(depth + 1, true, alpha, beta);
                        board[i][j] = ' ';
                        bestScore = min(score, bestScore);
                        beta = min(beta, bestScore);
                        if (beta <= alpha) break;
                    }
                }
            }
            return bestScore;
        }
    }
 // Hard AI using minimax
    void makeSmartAIMove() {
        int bestScore = -1000;
        pair<int, int> bestMove = {-1, -1};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(0, false, -1000, 1000);
                    board[i][j] = ' ';

                    if (score > bestScore) {
                        bestScore = score;
                        bestMove = {i, j};
                    }
                }
            }
        }

        if (bestMove.first != -1) {
            board[bestMove.first][bestMove.second] = 'O';
        }
    }

    // Show loading animation
    void showLoadingScreen() {
        clearScreen();
        cout << Colors::GREEN << "Loading Tic-Tac-Toe...\n" << Colors::RESET;

        for (int i = 0; i <= 10; i++) {
            cout << "[";
            for (int j = 0; j < 10; j++) {
                if (j < i) cout << "=";
                else cout << " ";
            }
            cout << "] " << i * 10 << "%\r";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(200));
        }

        cout << Colors::GREEN << "\nReady to play!\n" << Colors::RESET;
        this_thread::sleep_for(chrono::seconds(1));
    }

    // Display game description
    void showGameDescription() {
        clearScreen();
        cout << Colors::GREEN << "       TIC-TAC-TOE GAME DESCRIPTION\n";
        cout << "       -----------------------------\n\n" << Colors::RESET;
        cout << "Tic-Tac-Toe is a classic two-player game played on a 3x3 grid.\n";
        cout << "Players take turns marking a space in the grid, one using 'X' and the other using 'O'.\n";
        cout << "The goal is to be the first to get three of your marks in a row (horizontally, vertically, or diagonally).\n\n";
        cout << "How to Play:\n";
        cout << "1. Choose between single-player (vs AI) or two-player mode\n";
        cout << "2. When prompted, enter a number (1-9) corresponding to the position on the board\n";
        cout << "3. Try to get three in a row while blocking your opponent\n\n";
        cout << "Press Enter to return to the main menu...";
        cin.ignore();
        cin.get();
    }

public:
    // Constructor
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X'), vsAI(false), hardMode(false) {
        srand(time(0));
    }

    // Main game loop for single player mode
    void playSinglePlayer() {
        clearScreen();
        cout << Colors::GREEN << "Choose difficulty:\n";
        cout << "1. Easy\n";
        cout << "2. Hard\n";
        cout << "Enter your choice: " << Colors::YELLOW;

        int choice;
        while (!(cin >> choice) || (choice != 1 && choice != 2)) {
            cout << Colors::RED << "Invalid choice. Please enter 1 or 2: " << Colors::YELLOW;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << Colors::RESET;

        hardMode = (choice == 2);
        vsAI = true;

        char playAgain;
        do {
            initializeBoard();
            currentPlayer = 'X';

            while (true) {
                displayBoard();

                if (currentPlayer == 'X') {
                    getPlayerMove();
                } else {
                    cout << "AI is thinking...\n";
                    this_thread::sleep_for(chrono::seconds(1));

                    if (hardMode) {
                        makeSmartAIMove();
                    } else {
                        makeRandomAIMove();
                    }
                }

                if (checkWin(currentPlayer)) {
                    displayBoard();
                    cout << (currentPlayer == 'X' ? "You win!" : "AI wins!") << endl;
                    break;
                }

                if (isBoardFull()) {
                    displayBoard();
                    cout << "It's a draw!\n";
                    break;
                }

                switchPlayer();
            }

            cout << "Do you want Play again? (y/n): ";
            cin >> playAgain;
        } while (playAgain == 'y' || playAgain == 'Y');
    }
 // Main game loop for multiplayer mode
    void playMultiPlayer() {
        string player1, player2;
        clearScreen();

        cout << "Enter Player 1 name (X): ";
        cin >> player1;
        cout << "Enter Player 2 name (O): ";
        cin >> player2;

        char playAgain;
        do {
            initializeBoard();
            currentPlayer = 'X';

            while (true) {
                displayBoard();
                getPlayerMove();

                if (checkWin(currentPlayer)) {
                    displayBoard();
                    cout << (currentPlayer == 'X' ? player1 : player2) << " wins!\n";
                    break;
                }

                if (isBoardFull()) {
                    displayBoard();
                    cout << "It's a draw!\n";
                    break;
                }

                switchPlayer();
            }

            cout << "Do you want Play again? (y/n): ";
            cin >> playAgain;
        } while (playAgain == 'y' || playAgain == 'Y');
    }
    
   

   cout << Colors::RESET;

            switch (choice) {
                case 1:
                    playSinglePlayer();
                    break;
                case 2:
                    playMultiPlayer();
                    break;
                case 3:
                    showGameDescription();
                    break;
                case 4:
                    cout << "Thanks for playing!\n";
                    break;
            }
        } while (choice != 4);
    }
};

// ===== Part 6: Main Function =====

int main() {
    TicTacToe game;
    game.showMainMenu();              // Starts the game
    return 0;
}
