//
// Created by 10054 on 2022/9/30.
//

#include <stdio.h>

int main(){
   const double MOL = 6.02e23;
   const int MOL_PER_GTAM = 32;
   int mass = 6;

   double quantity = mass * 1.0 / 32 * MOL;

   printf("quantity = %.3e\nquantity = %.5g\n",
          quantity,quantity);

    return 0;
}