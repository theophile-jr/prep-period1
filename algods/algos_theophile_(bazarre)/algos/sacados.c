#include <stdio.h>
/*
L’algorithme construit progressivement toutes les sommes possibles à partir des poids disponibles. Pour chaque capacité intermédiaire j, il vérifie si elle peut être atteinte en ajoutant un des objets disponibles aux sommes déjà atteignables.

On commence avec la somme 0 comme atteignable.

Ensuite, pour chaque capacité de 1 à capacity, on regarde si en ajoutant un objet existant à une somme atteignable précédente on peut atteindre cette nouvelle capacité.

Si à la fin la capacité cible capacity est atteignable, alors il existe une combinaison d’objets qui correspond exactement à cette capacité.

Autrement dit : l’algorithme explore toutes les combinaisons possibles de poids, mais de manière intelligente grâce à la programmation dynamique.

teste toutes les combinaisons possibles (part de 0 ykk)
weighth 7 ? goal 7 ? 7-7 = 0 = true


if want cap 29, 29 - weight : lacking x, if x already reachable, then can reach, because x has been reachable same logic (starting with 0)
*/
int main(void) {
    int capacity;
    int weights[1000];
    int tmp_input = 0;
    int nbObject = 0;

    // tmp_input
    scanf("%d", &capacity);

    while (tmp_input != -1) {
        scanf("%d", &tmp_input);
        if (tmp_input < 0) {
            continue;
        }
        weights[nbObject] = tmp_input;
        nbObject++;
    }

    // START OF THE ALGORITHM
    int L[capacity +1];     // +1 car capacity 0 doit avoir un tab de taille 1
    L[0] = 1;

    int j;
    int o;

    // start j = 1 beacause L[0] == 1
    for(j = 1; j <= capacity; j++) {
        L[j] = 0;
        for(o = 0; o < nbObject; o++) {
            // in this case skip
            if(j-weights[o] < 0) continue;

            if(L[j-weights[o]] == 1) {
                L[j] = 1;
                break;                  //we don't want to earase previous results
            }
        }
    } //  weights first : so we really unlock progressfully


    if(L[capacity] == 1) {
        printf("OUI\r\n");
    } else {
        printf("NON\r\n");
    }

    return 0;
}
// +1 because we reallyw ant case for 0 