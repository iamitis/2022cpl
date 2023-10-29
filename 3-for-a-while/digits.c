//
// Created by 10054 on 2022/10/14.
//

#include <stdio.h>

int main() {
    int number = 0;
    scanf("%d", &number);

    int num_of_digits = 0;

    if (number == 0) {
        num_of_digits = 0;
    } else {
        while (number > 0) {
            number /= 10;
            num_of_digits++;
        }
    }


    do {
        number /= 10;
        num_of_digits++;
    } while (number > 0);

    printf("Numbers of digits is %d.\n", num_of_digits);


    return 0;
}