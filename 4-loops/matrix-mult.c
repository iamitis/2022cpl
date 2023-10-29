//
// Created by 10054 on 2022/10/26.
//
#include <stdio.h>

int main() {
    int m = 0, n = 0, p = 0;
    scanf("%d%d%d\n", &m, &n, &p);
    int A[100][100] = {0};
    int B[100][100] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int C[100][100] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int e = 0, f = 0; e < n; e++, f++) {
                C[i][j] += A[i][e] * B[f][j];
            }
        }
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < p - 1; j++) {
            printf("%d ", C[i][j]);
        }
        printf("%d\n", C[i][p - 1]);
    }
    for (int j = 0; j < p - 1; j++) {
        printf("%d ", C[m - 1][j]);
    }
    printf("%d", C[m - 1][p - 1]);

    return 0;
}