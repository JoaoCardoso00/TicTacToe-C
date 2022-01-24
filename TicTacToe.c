#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void printBoard(int board[3][3]);
void makeMove(int board[3][3]);
void makeComputerMove(int board[3][3]);
void printLoading();
bool checkWin(int board[3][3], bool *isGameOver, int *winner);
int checkDiagonals();
int checkColumns();
int checkRows();

int main() {
//      1 is X, 2 is Circle, 0 is empty
//     [0],[1],[0],
//     [0],[0],[2],
//     [0],[0],[0],

    char name[] = "";
    int board[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    bool isXNext = true;
    bool gameIsOver = false;
    int winner;

    //First interactions with user
    printf("Welcome to Tic Tac Toe in C\nPlease input your name before we begin: ");
    scanf("%s", &name);
    printf("Hello %s, Lets Begin!\n\n", name);

    printBoard(board);

    while (true)
    {
        if(!gameIsOver && isXNext) {
            printf("Whats your next move?\n");

            makeMove(board);
            isXNext = false;
            printBoard(board);
            if(checkWin(board, &gameIsOver, &winner)){
                break;
            }
            makeComputerMove(board);
            if(checkWin(board, &gameIsOver, &winner)){
                break;
            }
            printLoading();
            isXNext = true;
            printBoard(board);
            continue;
        }
    }
    switch (winner)
    {
    case 1:
        printf("\nPlayer Wins!!!\n");
        break;
    case 2:
        printf("\nComputer Wins!!!\n");
        break;
    }
    return 0;
}

void printBoard(int board[3][3]) {
    int x = 1;
    int y = 2;
    int z = 3;
    printf("  Board       example board\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j] == 1){
                printf("[X]");
            }else if (board[i][j] == 2) {
                printf("[O]");
            } else {
                printf("[ ]");
            }
        }
        printf("      [%d] [%d] [%d]", x, y, z);
        x += 3;
        y += 3;
        z += 3;
        printf("\n");
    }
};

void makeMove(int board[3][3]){

    int playerMove;
    scanf("%d", &playerMove);

    switch (playerMove)
    {
    case 1:
        if(board[0][0] == 0) {
            board[0][0] = 1;
            break;
        } else {
            printf("Square is not available, please pick another one\n");
            makeMove(board);
        }
    case 2:
        if(board[0][1] == 0) {
            board[0][1] = 1;
            break;
        } else {
            printf("Square is not available, please pick another one\n");
            makeMove(board);
        }
    case 3:
        if(board[0][2] == 0) {
            board[0][2] = 1;
            break;
        } else {
            printf("Square is not available, please pick another one\n");
            makeMove(board);
        }
    case 4:
        if(board[1][0] == 0) {
            board[1][0] = 1;
            break;
        } else {
            printf("Square is not available, please pick another one\n");
            makeMove(board);
        }
    case 5:
        if(board[1][1] == 0) {
            board[1][1] = 1;
            break;
        } else {
            printf("Square is not available, please pick another one\n");
            makeMove(board);
        }
    case 6:
        if(board[1][2] == 0) {
            board[1][2] = 1;
            break;
        } else {
            printf("Square is not available, please pick another one\n");
            makeMove(board);
        }
    case 7:
        if(board[2][0] == 0) {
            board[2][0] = 1;
            break;
        } else {
            printf("Square is not available, please pick another one\n");
            makeMove(board);
        }
    case 8:
        if(board[2][1] == 0) {
            board[2][1] = 1;
            break;
        } else {
            printf("Square is not available, please pick another one\n");
            makeMove(board);
        }
    case 9:
        if(board[2][2] == 0) {
            board[2][2] = 1;
            break;
        } else {
            printf("Square is not available, please pick another one\n");
            makeMove(board);
        }
    default:
        break;
    }
}

void makeComputerMove(int board[3][3]) {
    srand(time(0));
    int x = rand();
    int y = x % 9;
    int Move = y + 1;

    switch (Move)
    {
    case 1:
        if(board[0][0] == 0){
            board[0][0] = 2;
            break;
        } else {
            makeComputerMove(board);
        }
    case 2:
        if(board[0][1] == 0){
            board[0][1] = 2;
            break;
        } else {
            makeComputerMove(board);
        }
    case 3:
        if(board[0][2] == 0){
            board[0][2] = 2;
            break;
        } else {
            makeComputerMove(board);
        }
    case 4:
        if(board[1][0] == 0){
            board[1][0] = 2;
            break;
        } else {
            makeComputerMove(board);
        }
    case 5:
        if(board[1][1] == 0){
            board[1][1] = 2;
            break;
        } else {
            makeComputerMove(board);
        }
    case 6:
        if(board[1][2] == 0){
            board[1][2] = 2;
            break;
        } else {
            makeComputerMove(board);
        }
    case 7:
        if(board[2][0] == 0){
            board[2][0] = 2;
            break;
        } else {
            makeComputerMove(board);
        }
    case 8:
        if(board[2][1] == 0){
            board[2][1] = 2;
            break;
        } else {
            makeComputerMove(board);
        }
    case 9:
        if(board[2][2] == 0){
            board[2][2] = 2;
            break;
        } else {
            makeComputerMove(board);
        }
    default:
        break;
    }
}

void printLoading() {
    printf("\n");
    printf("Computing Move");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf("\n\n");
}

bool checkWin(int board[3][3], bool *isGameOver, int *winner) {
    int columnWin;
    int diagonalWin;
    int rowWin;

    columnWin = checkColumns(board);
    diagonalWin = checkDiagonals(board);
    rowWin = checkRows(board);

    if(columnWin == 1 || diagonalWin == 1 || rowWin == 1){
        *winner = 1;
        *isGameOver = true;
        return true;
    } else if (columnWin == 2 || diagonalWin == 2 || rowWin == 2) {
        *winner = 2;
        *isGameOver = true;
        return true;
    }
    return false;
}

int checkDiagonals(int board[3][3]) {
    if((board[0][0] == 1) && (board[1][1] == 1) && (board[2][2] == 1) || (board[0][2] == 1) && (board[1][1] == 1) && (board[2][0] == 1)) {
        return 1;
    } else if ((board[0][0] == 2) && (board[1][1] == 2) && (board[2][2] == 2) || (board[0][2] == 2) && (board[1][1] == 2) && (board[2][0] == 2)) {
        return 2;
    } else {
        return 0;
    }
}

int checkColumns(int board[3][3]) {
    if((board[0][0] == 1) && (board[1][0] == 1) && (board[2][0] == 1) || (board[0][1] == 1) && (board[1][1] == 1) && (board[2][1] == 1) || (board[0][2] == 1) && (board[1][2] == 1) && (board[2][2] == 1)) {
        return 1;
    } else if ((board[0][0] == 2) && (board[1][0] == 2) && (board[2][0] == 2) || (board[0][1] == 2) && (board[1][1] == 2) && (board[2][1] == 2) || (board[0][2] == 2) && (board[1][2] == 2) && (board[2][2] == 2)) {
        return 2;
    } else {
        return 0;
    }
}

int checkRows(int board[3][3]) {
    if((board[0][0] == 1) && (board[0][1] == 1) && (board[0][2] == 1) || (board[1][0] == 1) && (board[1][1] == 1) && (board[1][2] == 1) || (board[2][0] == 1) && (board[2][1] == 1) && (board[2][2] == 1)) {
        return 1;
    } else if ((board[0][0] == 2) && (board[0][1] == 2) && (board[0][2] == 2) || (board[1][0] == 2) && (board[1][1] == 2) && (board[1][2] == 2) || (board[2][0] == 2) && (board[2][1] == 2) && (board[2][2] == 2)) {
        return 2;
    } else {
        return 0;
    }
}