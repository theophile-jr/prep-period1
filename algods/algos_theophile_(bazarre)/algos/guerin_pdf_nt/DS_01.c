#include <stdio.h>
#define DIST 2.25
int main(void) {
    int n;
    scanf("%d", &n);
    int entiers[n];
    int i;
    double somme = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &entiers[i]);
        somme += entiers[i];
    }

    double moyenne = somme / n;
    int nbNorm = 0;

    for (i = 0; i < n; i++) {
        if (entiers[i] > moyenne - DIST && entiers[i] < moyenne + DIST) {
            nbNorm++;
        }
    }
    printf("%d\r\n", nbNorm);
    return 0;
}
