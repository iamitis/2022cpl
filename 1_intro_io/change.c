//
// Created by 10054 on 2022/10/1.
//
#include<stdio.h>

int main(){

    int rmb;

    scanf("%d",&rmb);

    int fif = rmb/50;
    int twe = (rmb - fif * 50)/20;       // = (rmb % 50) / 20
    int ten = (rmb - fif * 50 - twe * 20)/10;
    int fiv = (rmb - fif * 50 - twe * 20 - ten *10)/5;
    int one = rmb - fif * 50 - twe * 20 - ten *10 - fiv * 5;

   printf("%d\n%d\n%d\n%d\n%d\n",
           fif,twe,ten,fiv,one);
    return 0;
}