//
// Created by 10054 on 2022/11/29.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char *strL = malloc(1001 * sizeof(*strL));
        char *strR = malloc(1001 * sizeof(*strR));
        scanf("%s", strL);
        scanf("%s", strR);

        unsigned long long lenL = strlen(strL);

        int n = 0;
        for (; n < lenL; n++) {
            //find the first letter being same as *strR in strL
            if (*(strL + n) == *strR && strncmp(strL + n, strR, lenL - n) == 0) {
                break;
            }
        }

        //copy to another string to splice it with strR
        char *strLcp = malloc(2000 * sizeof(*strLcp));
        for (int j = 0; j < n; j++) {
            *(strLcp + j) = *(strL + j);
        }
        *(strLcp + n) = '\0';

        strcat(strLcp, strR);

        printf("%s\n", strLcp);
        free(strLcp);
        free(strL);
        free(strR);
    }

    return 0;
}