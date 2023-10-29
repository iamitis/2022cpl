//
// Created by 10054 on 2022/10/9.
//

#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0, min = 0;

    scanf("%d%d%d", &a, &b, &c);

    if (a > b) {
        if (b > c) {
            min = c;
        } else {
            min = b;
        }
    } else {
        if (a > c) {
            min = c;
        } else {
            min = a;
        }
    }

    printf("min{%d,%d,%d} = %d\n", a, b, c, min);

    return 0;
}