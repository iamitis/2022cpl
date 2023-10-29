//
// Created by 10054 on 2022/10/9.
//
#include <stdio.h>

int main() {
    int year = 0;
    scanf("%d", &year);

    int leap =
            ((year % 4 == 0 && year % 100 != 0) ||
             (year % 400 == 0));


    if (leap == 0) {
        printf("the year %d is a common year.\n", year);
    } else {
        printf("the year %d is a leap year.\n", year);
    }

    return 0;
}