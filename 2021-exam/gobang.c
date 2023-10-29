//
// Created by 10054 on 2023/2/18.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        char board[25][25] = {0};
        for (int j = 0; j < 20; ++j) {
            gets(board[j]);
        }
        printf("Not Sure\n");
    }
    return 0;
}