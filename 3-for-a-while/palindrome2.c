//
// Created by 10054 on 2022/10/19.
//
# include <stdio.h>

int main() {
    int n = 0;
    char string[10000] = {0};
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c", &string[i]);
    }

    int count = 0;
    for (int i = 0; i < n / 2; i++) {
        if (string[i] == 63 && string[n - i - 1] != 63) {
            string[i] = string[n - i - 1];
            printf("%c", string[i]);
        } else if (string[i] != 63) {
            printf("%c", string[i]);
        } else {
            if (count >= 10) {
                printf("%d", count);
            } else {
                printf("0%d", count);
            }
            count++;
        }
    }
    count--;
    for (int i = n / 2; i < n; i++) {
        if (string[i] == 63 && string[n - i - 1] != 63) {
            string[i] = string[n - i - 1];
            printf("%c", string[i]);
        } else if (string[i] != 63) {
            printf("%c", string[i]);
        } else {
            if (count > 10 && count % 10 != 0) {
                printf("%d", (count % 10) * 10 + count / 10);
            } else if(count % 10 == 0 && count != 0) {
                printf("0%d", count / 10);
            } else {
                printf("%d0", count % 10);
            }
            count--;
        }
    }

    return 0;
}