//
// Created by 10054 on 2022/10/12.
//


#include <stdio.h>

int main() {
    int n = 0;
    char letter[10005];
    scanf("%d", &n);

    letter[0] = '\n';
    for(int i = 0; i < n + 1; i++) {
        scanf("%c", &letter[i]);
    }
    int k = 0;
    scanf("%d", &k);

    for(int j = k; j >=1; j--) {
        printf("%c", letter[j]);
    }
    for(int p = n; p > k; p--) {
        printf("%c", letter[p]);
    }

    return 0;
}