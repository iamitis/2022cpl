//
// Created by 10054 on 2022/10/9.
//
#include <stdio.h>

int main() {
    int year = 0;
    scanf("%d", &year);

    int leap = 0;

    if (year % 4 != 0) {
        leap = 0;
    } else if (year % 100 != 0) {
        leap = 1;
    } else if (year % 400 == 0) {
        leap = 1;
    } else {
        leap = 0;
    }


    if (leap == 0) {
        printf("the year %d is a common year.\n", year);
    } else {
        printf("the year %d is a leap year.\n", year);
    }

    return 0;
}