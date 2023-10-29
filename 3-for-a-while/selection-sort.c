//
// Created by 10054 on 2022/10/14.
//2

#include <stdio.h>
#include <string.h>
#define LEN 20
int numbers[LEN] = {0};
int main() {

    int len = -1;
    while (scanf("%d", &numbers[++len]) != EOF);



    for (int i = 0; i < len; i++) {
        int min = numbers[i];
        int index_min = i;
        for (int j = i + 1; j < len; j++) {
            if (numbers[j] <= numbers[i]) {
                min = numbers[j];
                index_min = j;
            }
        }
        int temp = min;
        numbers[index_min] = numbers[i];
        numbers[i] = temp;
    }
    for (int i = 0; i < len; i++) {
        printf("%d", numbers[i]);
    }

    return 0;
}