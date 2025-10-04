#include <stdio.h>

int main () {
    int res = 0;
    int a, b, c;
    for (a = 1; a <= 9; a++) {
        for (b = 0; b <= 9; b++) {
            for (c = 0; c <= 9; c++) {
                if (a + c == 2*b) {
                    res++;
                }
            }
        }
    }
    printf("%d\r\n", res);
    return 0;
}