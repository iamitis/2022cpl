//
// Created by 10054 on 2022/11/1.
//
#include <stdio.h>
#include <math.h>

int Sum(int n, int t);

int main() {
    int n = 0;
    int t = 0;
    scanf("%d%d", &n, &t);
    int sum = Sum(n, t);
    printf("%d", sum);
    return 0;
}

int Sum(int n, int t) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            sum += t * pow(10, j);
        }
    }
    return sum;
}