typedef struct complexe_s {
    float x;
    float y;
} complexe_t;



/*
QUESTION 6 I Définir un type structutre Complexe avec deux champs de type float pour les parties
réelles et imaginaires. Écrire un programme qui lit deux nombres à virgule (i.e. scanf() avec "%f") pour en
faire une seule variable de type Complexe. Écrire ensuite une fonction void affiche(Complexe z) qui
affiche z sous la forme a + b.i si b > 0, ou a − b.i si b < 0.

*/
// #include <stdio.h>

// void affiche(complexe_t z) {
//   if (z.y > 0) {
//         printf("%.2f + %.2fi\n", z.x, z.y);
//     } else if (z.y < 0) {
//         printf("%.2f - %.2fi\n", z.x, -z.y);
//     } else {
//         printf("%.2f\n", z.x);
//     }
// }

// int main () {
//     complexe_t z;
//     printf("Entrez la partie réelle : ");
//     scanf("%f", &z.x);
//     printf("Entrez la partie imaginaire : ");
//     scanf("%f", &z.y);

//     affiche(z);
//     return 0;

// }

/*
QUESTION 7 I Écrire une fonction Complexe ajoute(Complexe z1, Complexe z2) qui renvoie la somme
de ses deux arguments. De même, écrire une fonction Complexe multiplie(Complexe z1, Complexe z2)
qui renvoie le produit de z1 et z2.
Utilisez ces fonctions pour afficher par exemple les valeurs de i
2
, i
3
, ou encore (1 + i)(i − 1).*/

#include <stdio.h>

void affiche(complexe_t z) {
  if (z.y > 0) {
        printf("%.2f + %.2fi\n", z.x, z.y);
    } else if (z.y < 0) {
        printf("%.2f - %.2fi\n", z.x, -z.y);
    } else {
        printf("%.2f\n", z.x);
    }
}

complexe_t ajoute(complexe_t z1, complexe_t z2) {
    complexe_t result;
    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return result;
}

complexe_t multiplie(complexe_t z1, complexe_t z2) {
    complexe_t result;
    result.x = z1.x * z2.x - z1.y * z2.y;
    result.y = z1.x * z2.y + z1.y * z2.x;
    return result;
}
int main() {
    // Définition de i (0 + 1i)
    complexe_t i = {0, 1};
    // Définition de 1 (1 + 0i)
    complexe_t un = {1, 0};
    // Définition de -1 (-1 + 0i)
    complexe_t moins_un = {-1, 0};

    // Calcul de i^2
    complexe_t i_carre = multiplie(i, i);
    printf("i^2 = ");
    affiche(i_carre);

    // Calcul de i^3 = i^2 * i
    complexe_t i_cube = multiplie(i_carre, i);
    printf("i^3 = ");
    affiche(i_cube);

    // Calcul de (1 + i) et (i - 1)
    complexe_t un_plus_i = ajoute(un, i);
    complexe_t i_moins_un = ajoute(i, moins_un);
    complexe_t produit = multiplie(un_plus_i, i_moins_un);
    printf("(1 + i)(i - 1) = ");
    affiche(produit);

    return 0;
}