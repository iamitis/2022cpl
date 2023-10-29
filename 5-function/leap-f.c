//
// Created by 10054 on 2022/11/1.
//
#include <stdio.h>
#include <stdbool.h>

bool IsLeapYear(int year);

int main() {
    int year = 0;
    scanf("%d", &year);

    bool leap = IsLeapYear(year);

    if (!leap) {
        printf("the year %d is a common year.\n", year);
    } else {
        printf("the year %d is a leap year.\n", year);
    }

    return 0;
}

bool IsLeapYear(int year) {
    return  ((year % 4 == 0 && year % 100 != 0) ||
             (year % 400 == 0));
}