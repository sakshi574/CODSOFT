//Here a simple implementation of a console-based Tic-Tac-Toe game in C++:

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;

vector<vector<char>> board(SIZE, vector<char>(SIZE, '-'));

void displayBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void playerInput(char player) {
    int row, col;
    cout << "Player " << player << ", enter your move (row and column): ";
    cin >> row >> col;
    row--; col--; // adjust for 0-based indexing
    if (board[row][col] == '-') {
        board[row][col] = player;
    } else {
        cout << "Invalid move, try again.\n";
        playerInput(player);
    }
}

bool checkForWin(char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // horizontal win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // vertical win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // diagonal win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // diagonal win
    }
    return false;
}

bool checkForDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                return false; // empty space found, not a draw
            }
        }
    }
    return true; // no empty spaces, it's a draw
}

int main() {
    char player = 'X';
    while (true) {
        displayBoard();
        playerInput(player);
        if (checkForWin(player)) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }
        if (checkForDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }
        player = (player == 'X') ? 'O' : 'X'; // switch players
    }
    cout << "Play again? (y/n): ";
    char playAgain;
    cin >> playAgain;
    if (playAgain == 'y') {
        board = vector<vector<char>>(SIZE, vector<char>(SIZE, '-')); // reset board
        main(); // recursive call to play again
    }
    return 0;
}