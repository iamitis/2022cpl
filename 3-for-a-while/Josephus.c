//
// Created by 10054 on 2022/10/21.
//
#include <stdio.h>

int main() {
    int n = 0, k = 0;
    scanf("%d%d", &n, &k);
    int jo[10000] = {0};
    for (int i = 0; i < 10000; i++) {
        jo[i] = 1;
    }

    int next[10000] = {0};
    for (int i = 1; i < n; i++) {
        next[i] = i + 1;
    }
    next [n] = 1;

    int i = 1;
    while (n > 1) {
        for (int j = 1; j < k - 1; j++) {
            i = next[i];
        }
        jo[next[i]] = 0;

        next[i] = next[next[i]];

        n--;
        i = next[i];
    }

    printf("%d", i);

    return 0;
}

