//
// Created by 10054 on 2022/10/14.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int main() {
    int max = 0,count = 0;
    scanf("%d", &max);

    for (int number = 2; number <= max; number++) {

        bool is_prime = true;
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            count++;
            printf("%d ", number);
        }
    }
    printf("\ncount = %d",count);

    return 0;
}