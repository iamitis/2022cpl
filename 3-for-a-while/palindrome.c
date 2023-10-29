//
// Created by 10054 on 2022/10/14.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 21
char string[LEN] = "";

int main() {
    scanf("%20s", &string);
    int count = 0;
    while (string[count] != 0) {
        count++;
    }
    bool is_palindrome = true;
    for (int i = 0, j = count - 1; i < j; i++, j--) {
        if (string[i] != string[j]) {
            is_palindrome = false;
            break;
        }
    }

    printf("\"%s\" is %s a palindrome\n", string, is_palindrome ? "" : "not");

    return 0;
}