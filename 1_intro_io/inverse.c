//
// Created by 10054 on 2022/10/1.
//

#include <stdio.h>

int main(){

  int mayi;
  scanf("%d",&mayi);
  int a=mayi/100%10;
  int b=mayi/1000%10;
  int c=mayi/10000;
  int d=mayi%10;
  int e=mayi/10%10;


  printf("%d%d%d%d%d",a,b,c,d,e);

    return 0;
}