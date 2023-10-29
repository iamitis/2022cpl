//
// Created by 10054 on 2022/10/1.
//

#include <math.h>
#include <stdio.h>

int main(){

    double pia,pib;

    pia = 4 * (4 * atan(1.0/5) - atan(1.0/239));
    pib = log(640320.0 * 640320.0 * 640320.0 + 744.0) *1.0 / sqrt(163.0);

    printf("%.15f\n%.15f",
           pia,pib);
    return 0;
}