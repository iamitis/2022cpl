//
// Created by 10054 on 2022/10/20.
//
#include <stdio.h>

int main() {
    int n = 0, t[500] = {0};
    char str[1001];
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {scanf("%c", &str[i]);}
    for (int i = 0; i < n; i++) {t[str[i]]++;}

    int max = 0;                           //求高，即最多的字母数
    for (int i = 65; i <= 90; i++) {
        if (t[i] > max) max = t[i];
    }
    for (int i = 97; i <= 122; i++) {
        if (t[i] > max) max = t[i];
    }

    for (int i = 0; i < max; i++) {
        for (int j = 97; j <= 122; j++) {
            if (t[j] == 0 && t[j - 32] == 0) continue;
            else {
                if (t[j] == 0 && t[j - 32] !=0) {
                    if (t[j - 32] >= max - i) {
                        printf("= ");
                    } else {
                        printf("  ");
                    }
                } else if (t[j] != 0 && t[j - 32] == 0) {
                    if (t[j] >= max - i) {
                        printf("= ");
                    } else {
                        printf("  ");
                    }
                } else if (t[j] != 0 && t[j - 32] != 0) {
                    if (t[j] >= max - i && t[j - 32] >= max - i) {
                        printf("== ");
                    } else if (t[j] < max - i && t[j - 32] >= max - i) {
                        printf(" = ");
                    } else if (t[j] >= max - i && t[j - 32] < max - i) {
                        printf("=  ");
                    } else {
                        printf("   ");
                    }
                }
            }
        }
        printf("%c", 10);
    }
    int count = 0;
    for (int i = 65; i <= 90; i++) {
        if (t[i] != 0 && t [i + 32] != 0) {
            count = count + 3;
        } else if ((t[i] != 0 && t[i + 32] == 0) || (t[i] == 0 && t[i + 32] != 0)) {
            count = count + 2;
        }
    }
    for (int i = 0; i < count - 1; i++) {
        printf("-");
    }
    printf("%c", 10);

    for (int i = 97; i <= 122; i++) {
        if (t[i] != 0 && t[i - 32] != 0) {
            printf("%c%c ", i, i - 32);
        } else if (t[i] == 0 && t[i - 32] != 0) {
            printf("%c ", i - 32);
        } else if (t[i] != 0 && t[i - 32] == 0) {
            printf("%c ", i);
        }
    }

    return 0;
}