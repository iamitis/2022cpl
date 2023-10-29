//
// Created by 10054 on 2022/11/6.
//
#include <stdio.h>

int Fib(int n);

int main(){
    int n = 0;
    scanf("%d", &n);

    printf("%d", Fib(n));
    return 0;
}

int Fib(int n) {
    if (n <= 2) {
        return n;
    }

    return Fib(n - 1) + Fib(n - 2);
}