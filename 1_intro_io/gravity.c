//
// Created by 10054 on 2022/10/1.
//

#include <stdio.h>

int main(){

    const double G = 6.674e-11;
    const double M = 77.15;
    double m,R;
    scanf("%lf %lf",&m,&R);
    double F = G * M * m/(R * R);
    printf("%.3e",F);


    return 0;
}