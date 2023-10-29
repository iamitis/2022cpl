//
// Created by 10054 on 2022/10/10.
//


#include <stdio.h>
#include <math.h>

int main() {
    int n = 0;
    float x = 0.0, he = 0.0;
    scanf("%f%d", &x, &n);

    for (int i = 0; i <=n; i++) {
        if(i % 2 == 0) {
            he = he + pow(x,2 * i + 1) / (2 * i + 1);
        } else {
            he = he - pow(x,2 * i + 1) / (2 * i + 1);
        }
    }

    printf("%.10f",4 * he);
    return 0;
}