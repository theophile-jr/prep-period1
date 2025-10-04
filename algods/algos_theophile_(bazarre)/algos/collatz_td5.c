#include <stdio.h>

int f(int x) {
    if (x % 2 == 0) {
        return x / 2;
    } else {
        return 3 * x + 1;
    }
}

int main() {
    int A;
    scanf("%d", &A);
    int res = A;
    int id = 0;
    while (res != 1) {
        if (id == 0) {
            res = res;
        } 
        if (id > 0) {
            res    = f(res);
        }
        printf("%d\r\n", res);
        id++;
    }
}