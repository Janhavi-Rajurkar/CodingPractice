#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int checkDraw(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int player = 1;
    int choice;
    int row, col;
    int gameStatus;

    while (1) {
        printBoard(board);
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter your choice: ", player);
        scanf("%d", &choice);

        if(choice > 9){
            printf("Invalid move, try again in next turn");
        }

        row = (choice - 1) / SIZE;
        col = (choice - 1) % SIZE;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = (player == 1) ? 'X' : 'O';
            gameStatus = checkWin(board);

            if (gameStatus == 1) {
                printBoard(board);
                printf("==> Player %d wins!\n", player);
                break;
            } else if (checkDraw(board)) {
                printBoard(board);
                printf("==> It's a draw!\n");
                break;
            }

            player++;
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    return 0;
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
        }
    }
    return 1;
}
