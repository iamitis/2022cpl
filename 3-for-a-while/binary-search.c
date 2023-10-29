//
// Created by 10054 on 2022/10/14.
//

#include <stdio.h>

#define LEN 10
int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

int main() {
    int key = 0;
    scanf("%d", &key);

    int low = 0;
    int index = -1;
    int high = LEN - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (key > dictionary[mid]) {
            low = mid + 1;
        } else if (key < dictionary[mid]) {
            high = mid - 1;
        } else {
            index = mid;
            high = index - 1;
        }
    }

    if (index == -1) {
        printf("Not found!\n");
    } else {
        printf("the index of %d is %d\n", key, index);
    }

    return 0;
}