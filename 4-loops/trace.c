//
// Created by 10054 on 2022/10/26.
//
#include <stdio.h>
#include <stdbool.h>
int main() {
    int n = 0, m = 0, xo = 0, y0 = 0;
    scanf("%d%d%d%d\n", &n, &m, &xo, &y0);
    int board[51][51] = {0};
    for (int row = 1; row <= n; row++) {
        char str[51] = {0};
        gets(str);
        for (int col = 1; col <= m; col++) {
            if (str[col - 1] == 35) board[row][col] = 1;
        }
    }

    int count = 0;
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            if (board[row][col]) count++;
        }
    }
    printf("%d\n", count);

    int vectors[4][2] = {0,1,
                         0,-1,
                         -1,0,
                         1,0};
    int vis[51][51] = {0};
    int x = xo, y = y0;
    int trace = 1;
    while (trace < count) {
        printf("%d %d\n", x, y);
        vis[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            int newI = x + vectors[k][0];
            int newJ = y + vectors[k][1];
            if (!vis[newI][newJ] && board[newI][newJ]) {
                x = newI; y = newJ;
                break;
            }
        }
        trace++;
    }
    printf("%d %d", x, y);
    return 0;
}