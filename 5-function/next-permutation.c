//
// Created by 10054 on 2022/11/1.
//
#include <stdio.h>

int NumberOfDecrement(int arr[], int n);
void Flip(int arr[], int n, int count);

int main() {
    int n = 0;
    int perm[2000] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &perm[i]);
    }

    int count = NumberOfDecrement(perm,n);

    int i = 1, cont = 0;
    while (cont == 0) {
        for (int j = n; j > n - count; j--) {
            if (perm[j] == perm[n - count] + i) {
                int temp = perm[j];
                perm[j] = perm[n - count];
                perm[n - count] = temp;
                cont = 1;
                break;
            }
        }
        i++;
    }

    Flip(perm, n, count);

    for (int j = 1; j <= n; j++) {
        printf("%d", perm[j]);
    }

    return 0;
}

int NumberOfDecrement(int arr[], int n) {
    int count = 1;
    int i = n;
    while (1) {
        if (arr[i] < arr[i - 1]) {
            count ++;
            i--;
        } else break;
    }
    return count;
}

void Flip(int arr[], int n, int count) {
    for (int i = n; i > (n - count / 2); i--) {
        int temp = arr[i];
        arr[i] = arr [n - count + n - i + 1];
        arr[n - count + n - i + 1] = temp;
    }
}