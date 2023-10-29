//
// Created by 10054 on 2022/10/21.
//
#include <stdio.h>

#define N 10050

int main() {
    int n = 0, k = 0;
    int ant[N] = {0};
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ant[i]);
    }
    int pivot = ant[k - 1];

    int l = 0, r = n - 1;
    while (r != l) {
        while (l < n) {
            if (l == r || ant[l] >= pivot) break;
            l++;
        }
        while (r > 0) {
            if (l == r || ant[r] < pivot) break;
            r--;
        }
        if (l != r) {
            int temp = ant[l];
            ant[l] = ant[r];
            ant[r] = temp;
        }
    }

    int i = 0;
    while (ant[i] != pivot) i++;

    for (int j = 0; j < n; j++) {
        if (j < i && ant[j] > pivot || j > i && ant[j] < pivot) {
           int temp = ant[j];
           ant[j] = ant[i];
           ant[i] = temp;
            break;
        }
    }

    for (int j = 0; j < n - 1; j++) {
        printf("%d ", ant[j]);
    }
    printf("%d", ant[n - 1]);
    return 0;
}