#include <stdio.h>

int main () {
    int n;
    int i;
    long fact;
    scanf("%d", &n);
    fact = 1;
    for (i=2; i<=n; i++) {
        fact = i*fact;
    }
    printf("%d\r\n", fact);
}
