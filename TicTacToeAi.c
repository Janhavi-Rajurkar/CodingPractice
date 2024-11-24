#include <stdio.h>
#include <limits.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int checkDraw(char board[SIZE][SIZE]);
int minimax(char board[SIZE][SIZE], int depth, int isMaximizing);
int bestMove(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int player = 1; // 1 for human, 2 for AI
    int choice;
    int row, col;
    int gameStatus;

    while (1) {
        printBoard(board);

        if (player == 1) { // Human's turn
            printf("Player %d, enter your choice: ", player);
            scanf("%d", &choice);

            if(choice > 9 || choice < 1){
                printf("Invalid move, try again.\n");
                continue;
            }

            row = (choice - 1) / SIZE;
            col = (choice - 1) % SIZE;

            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = 'X';
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

                player = 2; // Switch to AI
            } else {
                printf("Invalid move, try again.\n");
            }
        } else { // AI's turn
            printf("Computer's turn...\n");
            int aiMove = bestMove(board); // Get the best move for AI
            row = (aiMove - 1) / SIZE;
            col = (aiMove - 1) % SIZE;

            board[row][col] = 'O'; // AI plays 'O'
            gameStatus = checkWin(board);

            if (gameStatus == 1) {
                printBoard(board);
                printf("==> Computer wins!\n");
                break;
            } else if (checkDraw(board)) {
                printBoard(board);
                printf("==> It's a draw!\n");
                break;
            }

            player = 1; // Switch to human
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

int minimax(char board[SIZE][SIZE], int depth, int isMaximizing) {
    int score = checkWin(board);

    if (score == 1) {
        // Return score based on who won
        // Here suppose after the player has played his move and if its the Ai's turn then while deciding the next move Ai understood that it has lost the game. 
        // Therefore, if score == 1 -> Player won, AI lost and hence it returns -10 -> indicating its loss
        return isMaximizing ? -10 : 10;

        //Here if isMaximizing is set to 1 -> it means currently Human played and won the game and next is AI's turn
        //But human played and won and therefore isMaximizing will return -10 indicating Human won
    }
    if (checkDraw(board)) {
        return 0;
    }

    if (isMaximizing) {
        int bestScore = INT_MIN;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char backup = board[i][j];
                    board[i][j] = 'O';
                    int score = minimax(board, depth + 1, 0);
                    board[i][j] = backup;
                    bestScore = (score > bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = INT_MAX;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char backup = board[i][j];
                    board[i][j] = 'X';
                    int score = minimax(board, depth + 1, 1);
                    board[i][j] = backup;
                    bestScore = (score < bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    }
}

int bestMove(char board[SIZE][SIZE]) {
    int bestScore = INT_MIN;
    int move = -1;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char backup = board[i][j];
                board[i][j] = 'O';
                int score = minimax(board, 0, 0);
                board[i][j] = backup;

                if (score > bestScore) {
                    bestScore = score;
                    move = i * SIZE + j + 1;
                }
            }
        }
    }

    return move;
}