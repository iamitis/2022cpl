//
// Created by 10054 on 2022/11/1.
//
#include <stdio.h>

int main() {
    int p = 0, q = 0, r = 0;
    scanf("%d%d%d", &p, &q, &r);
    int B = 0;

    for (int i = 2; i <= 100; i++) {
        if (p % 10 < i && p / 10 < i && q % 10 < i && q / 10 < i && r % 10 < i && r / 10 < i) {
            if ((p % 10 + p / 10 * i) * (q % 10 + 1 / 10 * i) == r % 10 + r / 10 * i) {
                B = i;
                break;
            }
        }
    }
    printf("%d", B);
    return 0;
}