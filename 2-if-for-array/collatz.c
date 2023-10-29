//
// Created by 10054 on 2022/10/10.
//


#include <stdio.h>

int main() {
    int n = 0, i = 0;
    scanf("%d", &n);

    int a = n;
    while (a != 1) {
        if (a % 2 == 0) {
            a = a / 2;
        } else {
            a = a * 3 + 1;
        }
        i = i + 1;
    }

    int b = n;
    int numbers[100000]= {0};
    for (int j = 0; j < i; j++) {
        if (b % 2 == 0) {
            b = b/2;
        } else {
            b = b * 3 + 1;
        }
        numbers[j] = b;
    }

    int max = n;
    for (int p = 0; p < i; p++) {
        if(max < numbers[p]) {
            max = numbers[p];
        }
    }

    printf("%d %d",i, max);
    return 0;
}