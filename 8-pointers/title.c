//
// Created by 10054 on 2022/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *title = malloc(5000);
    gets(title);

    unsigned long long len = strlen(title);

    *title = *title >= 97 ? *title - 32 : *title;
    for (int i = 1; i < len; i++) {
        *(title + i)  = (*(title + i) < 97 && *(title + i) != ' ') ? *(title + i) + 32 : *(title + i);
    }
    for (int i = 1; i < len - 1; i++) {
        if (*(title + i) == ' ') {
            *(title + i + 1)  = (*(title + i + 1) >= 97) ? *(title + i + 1) - 32 : *(title + i + 1);
        }
    }

    for (int i = 0; i <len; i++) {
        printf("%c", *(title + i));
    }
    free(title);
    return 0;
}