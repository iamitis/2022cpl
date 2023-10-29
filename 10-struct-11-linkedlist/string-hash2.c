//
// Created by 10054 on 2022/12/28.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int m = 0, q = 0;
    scanf("%d%d", &m, &q);
    char string[500000];
    char str[500000][1000];
    for (int i = 0; i < m; i++) {
        scanf("%s", *(string + i));
    }

    for (int i = 0; i < q; i++) {
        scanf("%s", *(str + i));
        int k = 0;
        for (int j = 0; j < m; j++) {
            if (strcmp(*(string + j), *(str + i)) == 0) {
                k = 1;
                break;
            }
        }
        printf(k ? "Yes\n" : "No\n");
    }

    return 0;
}