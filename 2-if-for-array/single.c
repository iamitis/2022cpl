//
// Created by 10054 on 2022/10/10.
//
#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d\n", &n);

    int numbers[100001] = {0};
    for (int i = 0; i < 2 * n - 1; i++) {
        scanf("%d", &numbers[i]);
    }

    int j = 0, cishu[100001] = {0};
    for (j = 0; j < 2 * n + 1; j++) {
        cishu[numbers[j]] = cishu[numbers[j]] + 1;
    }

    int p = 0, q = 0;
    for (p = 0; p < 100001; p++) {
        if(cishu[p] % 2 != 0) {
            q = p;
        }
    }

    printf("%d", q);

    return 0;
}