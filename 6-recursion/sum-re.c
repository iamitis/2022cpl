//
// Created by 10054 on 2022/11/6.
//
#include <stdio.h>

int Sum(const int nums[], int len);

int main() {
    int numbers[] = {1, 2, 3, 4, 5};

    // sizeof: operator
    int sum = Sum(numbers, sizeof numbers / sizeof (int));
    printf("sum = %d\n", sum);

    return 0;
}

int Sum(const int nums[], int len) {
    if (len == 0) {
        return 0;
    }

    int partial_sum = Sum(nums, len - 1);

    return partial_sum + nums[len - 1];
}