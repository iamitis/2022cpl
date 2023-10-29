//
// Created by 10054 on 2022/11/9.
//
#include <stdio.h>
#include <math.h>

int tri[100][100] = {0};

int Paint(int n, int x, int y);

int main() {
    int n = 0;
    scanf("%d", &n);

    int x = 1;
    int y = pow(2, n);

    Paint(n, x, y);

    for (int i = 1; i <= pow(2,n) - 1; i++) {
        for (int j = 1; j <= pow(2, n + 1); j++) {
            if (tri[i][j] == 0) printf(" ");
            if (tri[i][j] == 1) printf("/");
            if (tri[i][j] == 2) printf("\\");
            if (tri[i][j] == 3) printf("_");
        }
        printf("\n");
    }
    for (int j = 1; j <= pow(2, n + 1); j++) {
        int r = pow(2, n);
        if (tri[r][j] == 0) printf(" ");
        if (tri[r][j] == 1) printf("/");
        if (tri[r][j] == 2) printf("\\");
        if (tri[r][j] == 3) printf("_");
    }

    return 0;
}

int Paint(int n, int x, int y) {
    if (n == 1) {
        tri[x][y] = 1; tri[x][y + 1] = 2;
        tri[x + 1][y - 1] = 1; tri[x + 1][y] = 3; tri[x + 1][y + 1] = 3; tri[x + 1][y + 2] = 2;
    } else {
        int x1 = x + pow(2, n - 1);
        int y1 = y - pow(2, n - 1);
        int y2 = y + pow(2, n - 1);
        Paint(n - 1, x, y);
        Paint(n - 1, x1, y1);
        Paint(n - 1, x1, y2);
    }
}

