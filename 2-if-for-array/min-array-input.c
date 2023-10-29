//
// Created by 10054 on 2022/10/9.
//
#include <stdio.h>
#define NUM 5

int main() {

    int numbers[NUM] = {0};

    for (int  i = 0; i < NUM; i++){
        scanf("%d",&numbers[i]);
    }

    int min = numbers[0];
    for (int i = 1; i < NUM; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    printf("min: %d\n", min);

    return 0;
}