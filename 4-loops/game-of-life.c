//
// Created by 10054 on 2022/10/22.
//
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define SIZE 6
#define MAX_ROUND 10
const int board[SIZE][SIZE] = {
    [1][1] = 1, [1][2] = 1,
    [2][1] = 1, [2][2] = 1,
    [3][3] = 1, [3][4] = 1,
    [4][3] = 1, [4][4] = 1
};
int main() {
    int old_board[SIZE + 2][SIZE + 2] = {0};
    for (int row = 0; row < SIZE + 2; row++)
        for (int col = 0; col < SIZE + 2; col++) {
            if (row == 0 || row == SIZE + 1 || col == 0 || col == SIZE + 1) {
                old_board[row][col] = 0;
            } else {
                old_board[row][col] = board[row - 1][col - 1];
            }
        }

    for (int row = 1; row < SIZE + 1; row ++) {
        for (int col = 1; col < SIZE + 1; col++) {
            printf(old_board[row][col] ? "*" : " ");
        }
        printf("\n");
    }

    Sleep(1000);
    int next_board[SIZE + 2][SIZE + 2] = {0};
    for (int round = 1; round < MAX_ROUND; round++) {
        for (int row = 1; row < SIZE + 1; row++) {
            for (int col = 1; col < SIZE + 1; col++) {
                int neighbours =
                        old_board[row - 1][col - 1] +
                        old_board[row - 1][col] +
                        old_board[row - 1][col + 1] +
                        old_board[row][col - 1] +
                        old_board[row][col + 1] +
                        old_board[row + 1][col - 1] +
                        old_board[row + 1][col] +
                        old_board[row + 1][col + 1];
                if (old_board[row][col]) {
                    next_board[row][col] = (neighbours == 2 || neighbours == 3);
                } else {
                    next_board[row][col] = (neighbours == 3);
                }
            }
        }

        Sleep(1000);
        system("cls");
        for (int row = 1; row < SIZE + 1; row++) {
            for (int col = 1; col < SIZE + 1; col++) {
                printf(next_board[row][col] ? "*" : " ");
                old_board[row][col] = next_board[row][col];
            }
            printf("\n");
        }

    }



        return 0;
}