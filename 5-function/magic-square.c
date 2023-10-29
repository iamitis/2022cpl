//
// Created by 10054 on 2022/11/1.
//
#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int square[100][100] = {0};
    int a = 2;
    square[1][n / 2 + 1] = 1;
    int row = 1, col = n / 2 + 1;
    while (a <= n * n) {
        if (row - 1 < 1) {
            if (col + 1 > n) {
                if (square[n][1] != 0) {
                    row += 1;
                    square[row][col] = a;
                } else {
                    row = n; col = 1;
                    square[row][col] = a;
                }
            } else {
                if (square[n][col + 1] != 0) {
                    row += 1;
                    square[row][col] = a;
                }
                else {
                    row = n; col += 1;
                    square[row][col] = a;
                }
            }
        } else {
            if (col + 1 > n) {
                if (square[row - 1][1] != 0) {
                    row += 1;
                    square[row][col] = a;
                } else {
                    row -= 1; col = 1;
                    square[row][col] = a;
                }
            } else {
                if (square[row - 1][col + 1] != 0) {
                    row += 1;
                    square[row][col] = a;
                } else {
                    row -= 1; col += 1;
                    square[row][col] = a;
                }
            }
        }
        a++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j =1 ; j <= n; j++) {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }
    return 0;
}