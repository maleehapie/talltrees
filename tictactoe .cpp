#include <iostream>

const int GRID_SIZE = 3;

bool isValidMove(char grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    return grid[row][col] == '-';
}

bool checkForWin(char grid[GRID_SIZE][GRID_SIZE], char player) {
    // Check rows and columns for a win
    for (int i = 0; i < GRID_SIZE; i++) {
        bool rowWin = true, colWin = true;

        for (int j = 0; j < GRID_SIZE; j++) {
            rowWin &= (grid[i][j] == player);
            colWin &= (grid[j][i] == player);
        }

        if (rowWin || colWin) return true;
    }

    // Check diagonals for a win
    bool diagWin1 = true, diagWin2 = true;

    for (int i = 0; i < GRID_SIZE; i++) {
        diagWin1 &= (grid[i][i] == player);
        diagWin2 &= (grid[i][GRID_SIZE - 1 - i] == player);
    }

    return diagWin1 || diagWin2;
}

bool checkForDraw(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == '-') return false;
        }
    }

    return true;
}

void displayBoard(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void playGame() {
    char grid[GRID_SIZE][GRID_SIZE] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    char currentPlayer = 'X';
    bool isGameActive = true;

    while (isGameActive) {
        displayBoard(grid);
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row col): ";
        std::cin >> row >> col;

        if (isValidMove(grid, row - 1, col - 1)) {
            grid[row - 1][col - 1] = currentPlayer;

            if (checkForWin(grid, currentPlayer)) {
                displayBoard(grid);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            }

            if (checkForDraw(grid)) {
                displayBoard(grid);
                std::cout << "The game is a draw." << std::endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move, try again." << std::endl;
        }
    }
}

int main() {
    bool playAgain = true;

    while (playAgain) {
        playGame();
        char response;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> response;

        if (response != 'y' && response != 'Y') {
            playAgain = false;
        }
    }

    return 0;
}