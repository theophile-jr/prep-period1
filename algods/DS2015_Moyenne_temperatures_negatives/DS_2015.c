#include <stdio.h>

int main(void) {
    int nbTemps;
    scanf("%d", &nbTemps);
    double temps[nbTemps];
    int i;
    for (i = 0; i < nbTemps; i++) {
        scanf("%lf", &temps[i]);
    }
    double somme = 0, nbNegatifs = 0;
    for (i = 0; i < nbTemps; i++) {
        if (temps[i] <= 0) {
            nbNegatifs++;
            somme += -temps[i];
        }
    }
    if (nbNegatifs == 0) {
        printf("-\r\n");
    } else {
        double moyenne = -somme / nbNegatifs;
        printf("%lf\r\n", moyenne);
    }
    return 0;
}