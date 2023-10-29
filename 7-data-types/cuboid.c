//
// Created by 10054 on 2022/11/18.
//
#include <stdio.h>

int main() {
    int T = 0;
    scanf("%d", &T);
    int x[60] = {0}, z[60] = {0}, y[60] = {0};
    for (int i = 1; i <= T; i++) {
        scanf("%d%d%d", &x[i], &z[i], &y[i]);
    }

    for (int i = 1; i <= T; i++) {

        int cub[30][30] = {0};

        for (int row = 1; row <= (y[i] + z[i]) * 2 + 1; row++) {
            if (row % 2 != 0) {
                for (int col = 1; col <= (z[i] + x[i]) * 2 + 1; col++) {
                    if (col % 2 != 0) { cub[row][col] = 1; }
                    else { cub[row][col] = 2; }
                }
            } else {
                for (int col = 1; col <= (z[i] + x[i]) * 2 + 1; col++) {
                    if (col % 2 != 0) { cub[row][col] = 3; }
                    else { cub[row][col] = 4; }
                }
            }
        }

        for (int row = 1; row <= z[i] * 2; row++) {
            //左上角放空
            for (int col = 1; col <= z[i] * 2 - row + 1; col++) {
                cub[row][col] = 4;
            }
            //中顶斜线和空格
            for (int col = z[i] * 2 - row + 2; col <= (z[i] + x[i]) * 2 + 1 - row + 1; col++) {
                if (row % 2 == 0) {
                    cub[row][col] = (col % 2 == 0) ? 5 : 4;
                }
            }
        }
        //右下角放空
        for (int row = (y[i] + z[i]) * 2 + 1; row > y[i] * 2 + 1; row--) {
            for (int col = (z[i] + x[i]) * 2 + 1; col > x[i] * 2 + 1 + (y[i] + z[i]) * 2 + 1 - row; col--) {
                cub[row][col] = 4;
            }
        }
        //中右斜线和空格
        for (int row = z[i] * 2 + 1; row <= y[i] * 2  + 1; row++) {
            for (int col = x[i] * 2 + 2; col <= (z[i] + x[i]) * 2; col++) {
                if (col % 2  == 0) {
                    cub[row][col] = (row % 2 == 0) ? 5 : 4;
                }
            }
        }
        //右上斜线和空格
        if(z[i] <= y[i]) {
            for (int row = 1; row <= z[i] * 2; row++) {
                for (int col = (z[i] + x[i]) * 2; col > (z[i] + x[i]) * 2 + 1 - row + 1; col--) {
                    if (col % 2 == 0) {
                        cub[row][col] = (row % 2 == 0) ? 5 : 4;
                    }
                }
            }
        }

        if (z[i] > y[i]) {
            for (int row = 1; row <= z[i] * 2; row++) {
                for (int col =  (z[i] + x[i]) * 2 + 1 - row + 2; col < x[i] * 2 + 1 + (y[i] + z[i]) * 2 + 1 - row; col++) {
                    if (col % 2 == 0) {
                        cub[row][col] = (row % 2 == 0) ? 5 : 4;
                    }
                }
            }
        }
        //右下斜线和空格
        for (int row = y[i] * 2 + 2; row <= (z[i] + y[i]) * 2; row ++) {
            for (int col = x[i] * 2 + 2; col <= x[i] * 2 + 1 + ((y[i] + z[i]) * 2 + 1 - row); col++) {
                if (col % 2 == 0) {
                    cub[row][col] = (row % 2 == 0) ? 5 : 4;
                }
            }
        }
        if (z[i] > y[i]) {
            for (int row = 1; row <= z[i] * 2; row++) {
                //左上角放空
                for (int col = 1; col <= z[i] * 2 - row + 1; col++) {
                    cub[row][col] = 4;
                }
            }
            //中顶补全
            for (int row = 1; row <= z[i] * 2; row++) {
                for (int col = z[i] * 2 - row + 2; col <= (z[i] + x[i]) * 2 + 1 - row + 1; col++) {
                    if (row % 2 != 0 && col % 2 == 0) {
                        cub[row][col] = 2;
                    }
                }
            }
        }

        for (int row = 1; row <=(z[i] + y[i]) * 2 + 1; row++) {
            for (int col = 1; col <= (z[i] + x[i]) * 2 + 1; col++) {
                if (cub[row][col] == 1) {printf("+");}
                if (cub[row][col] == 2) {printf("-");}
                if (cub[row][col] == 3) {printf("|");}
                if (cub[row][col] == 4) {printf(" ");}
                if (cub[row][col] == 5) {printf("/");}
            }
            printf("\n");
        }
    }

    return 0;
}