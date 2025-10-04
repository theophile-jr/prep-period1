/* C code below */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int rev(int a) {
   int res = 0;
   while (a != 0) {
      res = res * 10 + a % 10;
      a /= 10;
   }
   return res;
}

int prime(int n) {
   for (int i = 2; i <= sqrt(n); i++) {
      if ((n % i) == 0) //% ou /  -> bien capter logique stp 
         return 0;
   }
   return 1;
}

int count(int n) {
   int count = 0;
   for (int i = 2; i <= n; i++) {
      if ((prime(i) && prime(rev(i)) && (rev(i) != i))) {
         count++;
      }
   }
   return count;
}

int main () {
    printf("%d\n", count(100)); // Should be 8 (13, 17, 31, 37, 71, 73, 79, 97)
printf("%d\n", count(98765)); // Should be 1606
}