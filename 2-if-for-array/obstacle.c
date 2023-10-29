//
// Created by 10054 on 2022/10/12.
//


#include <stdio.h>

int main() {
    int x = 0, y = 0, xa = 0, ya = 0, xb = 0, yb = 0, xc = 0, yc = 0;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);

    x = (xa - xb) >= 0 ? xa - xb : xb - xa;
    y = (ya - yb) >= 0 ? ya - yb : yb - ya;

    if (((xb - xa) >= 0 ? (xc <= xb && xc >= xa) : (xc >= xb && xc <= xa)) &&
        ((yb - ya) >= 0 ? (yc <= yb && yc >= ya) : (yc >= yb && yc <= ya))) {  // 障碍在范围内
        if (xa != xb && ya != yb) {
            printf("%d\n", x + y);
            if ((xc != xa && xc != xb && yc != ya && yc != yb) || (xb == xc) || (ya == yc)) { //在中间 或 与蚂蚁同高 或 与终点同轴
                if (ya >= yb) {
                    for (int j = 0; j < ya - yb; j++) {
                        printf("D");
                    }
                    for (int p = 0; p < (xa - xb >= 0 ? xa - xb : xb - xa); p++) {
                        printf(xa - xb >= 0 ? "L" : "R");
                    }
                } else {
                    for (int j = 0; j < yb - ya; j++) {
                        printf("U");
                    }
                    for (int p = 0; p < (xa - xb >= 0 ? xa - xb : xb - xa); p++) {
                        printf(xa - xb >= 0 ? "L" : "R");
                    }
                }
            } else {                                            //障碍与蚂蚁同轴 或 与终点同高
                if (xa >= xb) {
                    for (int j = 0; j < xa - xb; j++) {
                        printf("L");
                    }
                    for (int p = 0; p < (ya - yb >= 0 ? ya - yb : yb - ya); p++) {
                        printf(ya - yb >= 0 ? "D" : "U");
                    }
                } else {
                    for (int j = 0; j < xb - xa; j++) {
                        printf("R");
                    }
                    for (int p = 0; p < (ya - yb >= 0 ? ya - yb : yb - ya); p++) {
                        printf(ya - yb >= 0 ? "D" : "U");
                    }
                }
            }
        } else {
            if ((xa == xb && ya != yb) || (xa != xb && yb == ya)) {        //三点一线
                printf("%d\n", x + y + 2);
                if (yc == ya) {
                    printf("D");
                    for (int j = 0; j < (xa - xb >= 0 ? xa - xb : xb - xa); j++) {
                        printf(xa - xb >= 0 ? "L" : "R");
                    }
                    printf("U");
                } else {
                    printf("R");
                    for (int p = 0; p < (ya - yb >= 0 ? ya - yb : yb - ya); p++) {
                        printf(ya - yb >= 0 ? "D" : "U");
                    }
                    printf("L");
                }
            }
        }
    } else {                                                            //障碍在范围外
        printf("%d\n", x + y);
        if (xa >= xb) {
            for (int j = 0; j < xa - xb; j++) {
                printf("L");
            }
            for (int p = 0; p < (ya - yb >= 0 ? ya - yb : yb - ya); p++) {
                printf(ya - yb >= 0 ? "D" : "U");
            }
        } else {
            for (int j = 0; j < xb - xa; j++) {
                printf("R");
            }
            for (int p = 0; p < (ya - yb >= 0 ? ya - yb : yb - ya); p++) {
                printf(ya - yb >= 0 ? "D" : "U");
            }
        }
    }

    return 0;
}

