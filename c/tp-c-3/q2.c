#include <stdio.h>
#include "biblio.h"

#define MAX_SIZE 100

// int main() {
//     int montableau[10];

//     printf("Entrez 10 nombres entiers :\n");
//     for (int i = 0; i < 10; i++) {
//         scanf("%d", &montableau[i]);
//     }

//     printf("Vous avez saisi :\n");
//     for (int i = 0; i < 10; i++) {
//         printf("%d ", montableau[i]);
//     }
//     printf("\n");

//     printf("%d\n", min(montableau, 10));
//     printf("%d\n", max(montableau, 10));
//     printf("%d\n", moyen(montableau, 10));
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;

    if (scanf("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "Erreur: N doit être un entier positif.\n");
        return 1;
    }

    int *montableau = malloc(N * sizeof(int));
    if (montableau == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &montableau[i]) != 1) {
            fprintf(stderr, "Erreur de lecture.\n");
            free(montableau);
            return 1;
        }
    }

    int min = montableau[0];
    int max = montableau[0];
    long somme = montableau[0];

    for (int i = 1; i < N; i++) {
        if (montableau[i] < min) min = montableau[i];
        if (montableau[i] > max) max = montableau[i];
        somme += montableau[i];
    }

    // Calcul de la moyenne entière
    int moy = (int)(somme / N);

    // Affichage
    printf("N=%d min=%d max=%d moy=%d\n", N, min, max, moy);

    // Libération de la mémoire
    free(montableau);

    return 0;
}
