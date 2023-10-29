//
// Created by 10054 on 2022/11/15.
//
#include <stdio.h>

void Sort(int value[], int vol[], int n);

int Add(int value[], int vol[], int n, int L, int price);

int main(){
    int n = 0, L  = 0;
    scanf("%d%d\n", &n, &L);
    int value[10004] = {0};
    int vol[10004] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &vol[i]);
    }

    int price = 0;

    Sort(value, vol, n);

    price = Add(value, vol, n, L, price);

    printf("%d", price);
    return 0;
}

void Sort(int value[], int vol[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = value[i];
        for (int j = i + 1; j < n; j++) {
            if (value[j] < min) {
                int temp = min;
                value[i] = value[j];
                min = value[j];
                value[j] = temp;
                temp = vol[j];
                vol[j] = vol[i];
                vol[i] = temp;
            }
        }
    }
}

int Add(int value[], int vol[], int n, int L, int price) {
    for (int i = n - 1; i >= 0; i--) {
        if (L > vol[i]) {
            price += value[i] * vol[i];
            L -= vol[i];
        } else {
            price += value[i] * L;
            return price;
        }
    }
}