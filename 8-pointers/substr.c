//
// Created by 10054 on 2022/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *strS = malloc(100005);
    char *strT = malloc(100005);
    gets(strS);
    gets(strT);

    unsigned long long lenS = strlen(strS);
    unsigned long long lenT = strlen(strT);

    for (int i = 0; i < lenS; i++) {
        int same = 1;
        for (int j = 0; j < lenT; j++) {
            same = *(strS + i + j) == *(strT + j);
            if (same == 0) break;
        }
        if (same) {
            printf("%d ", i);
        }
    }

    free(strS);
    free(strT);

    return 0;
}