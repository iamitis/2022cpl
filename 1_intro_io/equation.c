//
// Created by 10054 on 2022/10/1.
//

#include <stdio.h>
#include <math.h>

int main(){

    int p,q;

    scanf("%d %d",&p,&q);

    double pb = (q*1.0/2)*(q*1.0/2) + pow(p*1.0/3,3);

    double x1;

    if(p>0)
       { x1 = pow(sqrt(pb) - q*1.0/2,1.0/3)  -  pow(sqrt(pb) +  q*1.0/2,1.0/3);}

    else if(p<0 && q>0)
       {x1 = -pow(-sqrt(pb) + q*1.0/2,1.0/3)  -  pow(sqrt(pb) + q*1.0/2,1.0/3);}

    else
       {x1 = pow(sqrt(pb) - q*1.0/2,1.0/3)  +  pow(-sqrt(pb) - q*1.0/2,1.0/3);}

    printf("%.3f",x1);

    return 0;
}