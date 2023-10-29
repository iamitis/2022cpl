//
// Created by 10054 on 2022/11/9.
//
#include <stdio.h>

int main(){
    int n = 0;
    int numbers[10000] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j >=1; j--) {
            if (numbers[j - 1] > numbers[i] || j == 1) {
                printf("%d ", j);
                break;
            }
        }
        for (int j = i; j <= n; j++) {
            if (numbers[j + 1] > numbers[i] || j == n) {
                printf("%d\n", j);
                break;
            }
        }
    }
    return 0;
}