//
// Created by 10054 on 2022/11/1.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool IsAbsPrime(int a);

int main() {
    int n = 0;
    scanf("%d", &n);
    if (n < 2) {
        printf("0");
    } else if (n == 2) {
        printf("1");
    } else {
        int count = 1;
        for (int i = 3; i <= n; i++) {
            if (IsAbsPrime(i)) count++;
        }
        printf("%d", count);
    }
    return 0;
}

bool IsAbsPrime(int a) {
    int b = 0;
    if (a < 10) b = a;
    else if (a < 100) b = a % 10 * 10 + a / 10;
    else if (a < 1000) b = a % 10 * 100 + a % 100 / 10 * 10 + a / 100;
    else b = 1;
    if (a >= b) {
        for (int i = 2; i <= sqrt(a); i++) {
            if (a % i == 0 || b % i == 0) {
                return false;
            }
        }
    } else {
        for (int i = 2; i <= sqrt(b); i++) {
            if (a % i == 0 || b % i == 0) {
                return false;
            }
        }
    }
    return true;
}