//
// Created by 10054 on 2022/10/14.
//

#include <stdio.h>

int main() {
    int lines;
    scanf("%d", &lines);

    for (int i = 0; i < lines; i++) {

        for (int j = 0; j < lines - 1 - i; j++) {
            printf(" ");
        }

        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}