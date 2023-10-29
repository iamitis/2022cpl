//
// Created by 10054 on 2022/10/26.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n = 0;
    scanf("%d\n", &n);
    char str[1010] = {0};
    gets(str);
    int len = strlen(str);
    char old_str[1010] = {0};
    memset(old_str, '.', sizeof(old_str));
    for (int i = 3; i < len + 3; i++) {
        old_str[i] = str[i - 3];
    }

    for (int round = 0; round < n; round++) {
        char new_str[1010] = {0};
        memset(new_str, '.', sizeof(new_str));
        for (int i = 3; i <= len + 2; i++) {
            if (old_str[i] == 65) {
                int count = 0;
                bool life = true;
                for (int j = i - 3; j <= i + 3; j++) {
                    if (old_str[j] == 66) {
                        life = false;
                        break;
                    } else if (old_str[j] == 65) count++;
                }
                if (life) {
                    if (count - 1 >= 2 && count - 1 <= 4) {
                        new_str[i] = 'A';
                    }
                }
            }
            if (old_str[i] == 66) {
                int count = 0;
                bool life = true;
                for (int j = i - 3; j <= i + 3; j++) {
                    if (old_str[j] == 65) {
                        life = false;
                        break;
                    } else if (old_str[j] == 66) count++;
                }
                if (life) {
                    if (count - 1 >= 2 && count - 1 <= 4) {
                        new_str[i] = 'B';
                    }
                }
            }
            if (old_str[i] == 46) {
                if (old_str[i - 3] + old_str[i - 2] + old_str[i - 1] + old_str[i + 1] + old_str[i + 2] + old_str[i + 3] == 314 ||
                    old_str[i - 3] + old_str[i - 2] + old_str[i - 1] + old_str[i + 1] + old_str[i + 2] + old_str[i + 3] == 333 ||
                    old_str[i - 3] + old_str[i - 2] + old_str[i - 1] + old_str[i + 1] + old_str[i + 2] + old_str[i + 3] == 352) {
                    new_str[i] = 'A';
                }
                if (old_str[i - 3] + old_str[i - 2] + old_str[i - 1] + old_str[i + 1] + old_str[i + 2] + old_str[i + 3] == 316 ||
                    old_str[i - 3] + old_str[i - 2] + old_str[i - 1] + old_str[i + 1] + old_str[i + 2] + old_str[i + 3] == 336 ||
                    old_str[i - 3] + old_str[i - 2] + old_str[i - 1] + old_str[i + 1] + old_str[i + 2] + old_str[i + 3] == 356) {
                    new_str[i] = 'B';
                }
            }
        }
        for (int j = 3; j <= len + 2; j++) {
            old_str[j] = new_str[j];
        }
    }

    for (int i = 3; i <= len + 2; i++) {
        printf("%c", old_str[i]);
    }

    return 0;
}