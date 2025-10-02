#include <stdio.h>

int main(void) {
    int nbMarche, nbPaliers, i;
    scanf("%d", &nbMarche);
    scanf("%d", &nbPaliers);
    int positionPaliers[nbMarche];
    for (i = 0; i < nbMarche; i++) positionPaliers[i] = 0;
    for (i = 0; i < nbPaliers; i++) {
        int position;
        scanf("%d", &position);
        positionPaliers[position] = 1;
    }

    int nbchemins[nbMarche + 1];
    for (i = 0; i < nbMarche; i++) nbchemins[i] = 0;
    nbchemins[0] = 1;

    for (i = 1; i <= nbMarche ; i++) {
        nbchemins[i] = nbchemins[i - 1];
        if (i-2 >= 0 && positionPaliers[i - 1] == 0) {
            nbchemins[i] += nbchemins[i-2];
        }
    }
    printf("%d\r\n", nbchemins[nbMarche]);

    return 0;
}