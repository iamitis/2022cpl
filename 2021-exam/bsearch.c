//
// Created by 10054 on 2023/2/18.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10006

int search(int *arr, int ns, int len);

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int arr[N] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < q; ++i) {
        int ns = 0;
        scanf("%d", &ns);
        printf("%d\n", search(arr, ns, n));
    }

    return 0;
}

int search(int *arr, int ns, int len) {
    int l = 0, r = len - 1;
    while (l < r) {
        int index = (l + r) / 2;
        if (arr[index] == ns)
            return index;
        if (arr[index] > ns) {
            r = index;
            continue;
        }
        if (l == index) break;
        l = index;
    }
    if (arr[r] == ns) return r;
    return -1;
}