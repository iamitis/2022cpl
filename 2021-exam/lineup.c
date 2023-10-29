//
// Created by 10054 on 2023/2/18.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int board[200][200] = {0};


int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            board[i][j] = i * m + j;
        }
    }
    for (int i = 0; i < q; ++i) {
        int x1, x2, x3, x4, y1, y2, y3, y4, a;
        scanf("%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &a);
        int raw = x2 - x1, col = y2 - y1;
        for (int j = 0; j <= raw; ++j) {
            for (int k = 0; k <= col; ++k) {
                board[x1 + j][y1 + k] ^= board[x3 + j][y3 + k] ^= board[x1 + j][y1 + k] ^= board[x3 + j][y3 + k];
            }
        }

        long long count = 0;
        for (int j = 1; j <= m; ++j) {
            count += board[a][j];
        }

        printf("%lld\n", count);
    }
    return 0;
}