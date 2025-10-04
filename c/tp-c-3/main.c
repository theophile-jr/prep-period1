#include <stdio.h>
#include "biblio.h"

// #define MAX_SIZE 100

// int main() {
//     int n;
//     int tab[MAX_SIZE];

//     printf("Entrez la taille du tableau (<= %d) : ", MAX_SIZE);
//     scanf("%d", &n);

//     if (n <= 0 || n > MAX_SIZE) {
//         printf("Taille invalide.\n");
//         return 1;
//     }

//     for (int i = 0; i < n; i++) {
//         printf("Entrez l'élément %d : ", i + 1);
//         scanf("%d", &tab[i]);
//     }

//     printf("\nSomme   = %d\n", somme(tab, n));
//     printf("Moyenne = %d\n", moyen(tab, n));
//     printf("Produit = %d\n", produit(tab, n));

//     return 0;
// }
