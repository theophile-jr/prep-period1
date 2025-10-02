#include <stdio.h>

int main(void) {
    int nbCartes, M, cartes[50], nbSolutions = 0, i, j, k;
    scanf("%d", &M);
    scanf("%d", &nbCartes);
    for (i = 0; i < nbCartes; i++) {
        scanf("%d", &cartes[i]);
    }

    for (i = 0; i < nbCartes; i++) {
        for (j = i+1; j < nbCartes; j++) {
            for (k = j+1; k < nbCartes; k++) {
                if (cartes[i] + cartes[j] + cartes[k] == M) {
                    nbSolutions++;
                }
            }
        }
    }
    printf("%d\r\n", nbSolutions);
    return 0;
}
