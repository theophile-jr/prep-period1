#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
#define MAX_SIZE 100

int main(void) {
    int N= 0;

    int *montableau = malloc(N * 2);
    if (montableau == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return 1;
    }

    while (1) {
        int nbt = scanf("%d", &montableau[N]);
        if (nbt != 1 || feof(stdin)) break;
        N++;
        montableau = realloc(montableau, (N + 1) * sizeof(int));
    }

    int min = montableau[0];
    int max = montableau[0];
    long somme = montableau[0];

    for (int i = 1; i < N; i++) {
        if (montableau[i] < min) min = montableau[i];
        if (montableau[i] > max) max = montableau[i];
        somme += montableau[i];
    }

    int moy = (int)(somme / N);

    printf("N=%d min=%d max=%d moy=%d\n", N, min, max, moy);

    free(montableau);

    return 0;
}
