/* C code below */
#include <stdio.h>
#include <stdlib.h>

int minCalories(int n, int step1, int step2, int step3) {
   int dp[n + 1];
   dp[0] = 0;
   dp[1] = step1;
   dp[2] = ((step1 + step1) < step2) ? step1 + step1 : step2;
   for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + step1;
      int opt2 = dp[i - 2] + step2;
      int opt3 = dp[i - 3] + step3;

      if (opt2 > opt3)
         dp[i] = opt3;
      if (opt2 < opt3)
         dp[i] = opt2;
   }
   // printf("%d\r\n", dp[n]);
   return dp[n];
}
void main () {
printf("%d\n", minCalories(7, 1, 3, 4)); // Should be 7
printf("%d\n", minCalories(7, 1, 1, 4)); // Should be 4
}