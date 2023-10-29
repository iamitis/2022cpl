//
// Created by 10054 on 2022/9/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
   int high=100;
   int number_of_tries=7;

   printf("let's play guess the number game\n"
          "the computer will generate a random number between 1 to %d."
          "you have %d. tries\n",high,number_of_tries);

   srand(time(NULL));
   int secret=rand() % high + 1;
   printf("Test:secret=%d\n",secret);
 while (number_of_tries>0) {
     printf("please input your guess number.\n"
            "you still have %d tries \n", number_of_tries);

     int guess = 0;
     scanf("%d", &guess);
     printf("Test:guess=%d\n", guess);

     if (guess == secret) {
         printf("you win\n");
         break;
     } else if (guess > secret) {
         printf("guess>secret\n");
     } else {
         printf("guess<secret\n");
     }
     number_of_tries--;
 }
          return 0;
}