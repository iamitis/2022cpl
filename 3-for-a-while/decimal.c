//
// Created by 10054 on 2022/10/19.
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int N = 0, len = 0;
    scanf("%d%d\n", &len, &N);

    char number[31] = {0};
    for (int i = 0; i < len; i++) {
        scanf("%c", &number[i]);
    }

    bool legal = true;
    for (int i = 0; i < len; i++) {
        if ((number[i] >= 48 && number[i] <= 57 && number[i] > N + 47) || (number[i] >= 65 && number[i] <= 90 && number[i] > N + 54)) {
            legal = false;
        }
    }

    int add = 0;
    if (legal) {
        for (int i = 0; i < len; i++) {
            if (number[len - i - 1] <= 57) {
                add = add + (number[len - i - 1] - 48) * pow(N, i);
            } else {
                add = add + (number[len - i - 1] - 55) * pow(N, i);
            }
        }
    }
    printf(legal ? "%d" : "Error", add);

    return 0;
}