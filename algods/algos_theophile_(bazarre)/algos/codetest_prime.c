/* C code below​​​​​​‌‌‌​​‌​​‌‌‌‌‌​‌‌‌​‌‌​​​​‌ */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rev(int a) {
   int res = 0;

   while (a != 0) {
      res = res * 10 + (a % 10);
      a /=  10;
   }
   return res;
}

int isPrime(int a) {
   if (a < 2) 
      return 0;
   for (int i = 2; i <= sqrt(a); i++) {
      if ((a % i) == 0)
         return 0;
   }
   return 1;
}

int count(int n) {
   int count = 0;

   for (int i = 0; i < n; i++) {
      if (isPrime(i) && isPrime(rev(i)) && (i != rev(i)))
         count++;
   }
   return count;
}

int main () {
    count(100); // Should be 8 (13, 17, 31, 37, 71, 73, 79, 97)
    count(98765); // Should be 1606
}
