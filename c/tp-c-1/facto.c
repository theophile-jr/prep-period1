// #include <stdio.h>
// int main() {
// int tab[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
// int res = tab[0];
// for (int i = 1; i < 10; i++) {
//      res *= tab[i];
// }
// printf("10! = %d", res);
// return 0;
// }

#include <stdio.h>
int facto(int n) {
     if (n == 1) return 1;
     return n * (facto (n - 1));

}
int main() {
     printf("1! = %i\n", facto(1));
     printf("3! = %i\n", facto(3));
     printf("5! = %i\n", facto(5));
     return 0;
}
