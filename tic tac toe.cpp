#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard() {
    char num = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

void displayBoard() {
    cout << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool placeMark(int pos) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == currentPlayer &&
           board[i][1] == currentPlayer &&
           board[i][2] == currentPlayer)
            return true;

        if(board[0][i] == currentPlayer &&
           board[1][i] == currentPlayer &&
           board[2][i] == currentPlayer)
            return true;
    }

    if(board[0][0] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][2] == currentPlayer)
        return true;

    if(board[0][2] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][0] == currentPlayer)
        return true;

    return false;
}

void switchPlayer() {
    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main() {
    string playAgain;

    do {
        initializeBoard();
        currentPlayer = 'X';
        int moves = 0;
        bool win = false;

        while(moves < 9 && !win) {
            displayBoard();
            int choice;
            cout << "Player " << currentPlayer << ", enter position (1-9): ";
            cin >> choice;

            if(choice < 1 || choice > 9 || !placeMark(choice)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            moves++;

            if(checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                win = true;
            } else {
                switchPlayer();
            }
        }

        if(!win) {
            displayBoard();
            cout << "Game Draw!\n";
        }

        cout << "Do you want to play again? (YES / NO): ";
        cin >> playAgain;

    } while(playAgain == "YES" || playAgain == "yes" || playAgain == "Yes");

    cout << "Program ended.\n";
    return 0;
}
