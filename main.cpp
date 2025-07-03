#include <bits/stdc++.h>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}
void playerMove(char symbol) {
    int move;
    cout << "Enter position (1-9): ";
    cin >> move;

    move--;
    int row = move / 3;
    int col = move % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
        board[row][col] = symbol;
    else {
        cout << "Invalid move. Try again.\n";
        playerMove(symbol);
    }
}
char checkWin() {
    // Rows & Columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' ';
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void aiMove() {
    srand(time(0));
    int move;
    do {
        move = rand() % 9;
    } while (board[move/3][move%3] == 'X' || board[move/3][move%3] == 'O');

    board[move/3][move%3] = 'O';
}
int main() {
    char winner = ' ';
    displayBoard();

    while (winner == ' ' && !isDraw()) {
        playerMove('X');
        displayBoard();

        winner = checkWin();
        if (winner != ' ' || isDraw()) break;

        cout << "AI's Move:\n";
        aiMove();
        displayBoard();

        winner = checkWin();
    }

    if (winner == 'X') cout << "You win!\n";
    else if (winner == 'O') cout << "AI wins!\n";
    else cout << "It's a draw!\n";

    return 0;
}
