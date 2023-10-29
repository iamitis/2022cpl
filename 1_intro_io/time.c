//
// Created by 10054 on 2022/10/1.
//

#include <stdio.h>

int main(){

    char month[10],weekday[10];
    int year,hour,min,sec,day;

    scanf("%s%d%d%s%d%d%d",
          month, &day, &year, weekday, &hour, &min, &sec);

    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d",
           weekday, month, day, hour, min, sec, year);
    return 0;
}