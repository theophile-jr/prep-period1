#include <stdio.h>

static int somme (int a, int b, int c) {
    return a + b + c;
}

int main () {
    long a,b,c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    printf("%d\r\n", somme(a,b,c));
    return 0;
}
