//
// Created by 10054 on 2022/11/6.
//
#include <stdio.h>

#define NUM 5

int Min(int nums[], int len);

int main(){
    int numbers[NUM] = {25, 34, 37, 45, 43};

    printf("%d", Min(numbers, NUM));

    return 0;
}

int Min(int nums[], int len) {
    if (len == 1) {
        return nums[0];
    }

    int partial_min = Min(nums, len - 1);
    return nums[len - 1] < partial_min ? nums[len - 1] : partial_min;
}
