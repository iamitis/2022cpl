//
// Created by 10054 on 2022/11/6.
//
#include <stdio.h>

int Find(int i);

int a[10000] = {0};

int main(){
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <=n; i++) {
        printf("%d ", Find(i));
    }

    return 0;
}

int Find(int i) {
    if (i == a[i]) {
        return i;
    }

    return Find(a[i]);
}