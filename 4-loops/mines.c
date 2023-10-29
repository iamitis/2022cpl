//
// Created by 10054 on 2022/10/22.
//
#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d\n", &n);
    int board[102][102] = {0};
    for (int row = 1; row <= n; row++) {
        char str[100] = {0};
        gets(str);
        for (int col = 1; col <= n; col++) {
            if (str[col - 1] == 111) board[row][col] = 0;
            else board[row][col] = 1;
        }
    }

    int vectors[8][2] = {0,1,
                         0,-1,
                         1,0,
                         1,-1,
                         -1,0,
                         -1,1,
                         1,1,
                         -1,-1};

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            int count = 0;
            for (int k = 0; k < 8; k++) {
                int newI = row + vectors[k][0];
                int newJ = col + vectors[k][1];
                if (board[newI][newJ] == 1) {
                    count++;
                }
            }
            printf(board[row][col] ? "*" : "%d", count);
        }
        printf("\n");
    }

    return 0;
}