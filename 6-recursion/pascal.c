//
// Created by 10054 on 2022/11/6.
//
#include <stdio.h>

int Place(int a, int b);

int main(){
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);

    printf("%d", Place(a, b));

    return 0;
}

int Place (int a, int b) {
    if (a - 1 == 0 || b - 1 == 0 || b - 1 == a - 1) {
        return 1;
    }

    return Place(a - 1, b - 1) + Place(a - 1, b);
}