//
// Created by 10054 on 2023/2/18.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void Operate(int *arr, int index);

bool Check(int *arr, int num);

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int n, m;
        int arr[1003] = {0};
        int op[1003] = {0};
        scanf("%d%d", &n, &m);
        for (int j = 1; j <= n; ++j) {
            scanf("%d", arr + j);
        }
        for (int j = 0; j < m; ++j) {
            scanf("%d", op + j);
            Operate(arr, op[j]);
        }

        printf(Check(arr, n) ? "I love C programming language\n" : "mayi is a good teacher\n");
    }
    return 0;
}

void Operate(int *arr, int index) {
    int first = arr[index];
    for (int i = index; i > 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[1] = first;
}

bool Check(int *arr, int num) {
    for (int i = 1; i < num; ++i) {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}
