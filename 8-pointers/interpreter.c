//
// Created by 10054 on 2022/11/22.
//
#include <stdio.h>

int main(){
    int n = 0;
    scanf("%x", &n);

    float *flo = &n;

    printf("%d\n%u\n%.6f\n%.3e", n, n, *flo, *flo);
    return 0;
}