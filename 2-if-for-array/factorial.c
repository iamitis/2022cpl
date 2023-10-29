//
// Created by 10054 on 2022/10/10.
//


#include <stdio.h>

int main() {
    int num = 0, fac = 1, qumo = 0;
    scanf("%d", &num);

    for(int j = num; j >= 1; j--) {
        for (int i = j ; i > 1; i--) {
            fac = fac * i % 10007;
        }
        qumo = qumo + fac;
        fac = 1;
    }

    printf("%d",qumo % 10007);

    return 0;
}