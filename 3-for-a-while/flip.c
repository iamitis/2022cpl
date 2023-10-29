//
// Created by 10054 on 2022/10/18.
//
#include <stdio.h>

int main() {
    int counts[2001] = {0};
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j * (i + 1) < n; j++) {
            int xiabiao = j * (i + 1) - 1;
            counts[xiabiao]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (counts[i] % 2 != 0) {
            printf("%d ", i + 1);
        }
    }
    return 0;
}