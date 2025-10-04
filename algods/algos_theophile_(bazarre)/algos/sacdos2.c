#include <stdio.h>

int main(void) {
    int capacity;
    int objects[1000];
    int tmp_input = 0;
    objects[0] = 0;
    int nbObject = 1;

    scanf("%d", &capacity);

    while (tmp_input != -1) {
        scanf("%d", &tmp_input);
        if (tmp_input < 0) {
            continue;
        }
        objects[nbObject] = tmp_input;
        nbObject++;
    }

    int tab[nbObject][capacity + 1];

    for (int i = 0; i < capacity + 1; i++) {
        tab[0][i] = 0;
    }
    for (int i = 0; i < nbObject; i++)
        tab[i][0] = 1;
    
    for (int objY = 1; objY < nbObject; objY++) {
        for (int capaX = 1; capaX <= capacity; capaX++) {
            tab[objY][capaX] = 0;
            if (tab[objY - 1][capaX] == 1 || capaX - objects[objY] == 0 || (capaX - objects[objY] > 0 && tab[objY - 1][capaX - objects[objY]])) {
                tab[objY][capaX] = 1;
            }
        }
    }
     // est-ce que j'ai déjà atteint cette capacité avec le poids prec -> propager ; ou est-ce que ce poids pile permet d'atteinidre cette capacité; ou bien est-ce que si je rajoute cette capacité reste-t-il de la place, si oui voir si cette place restante a déjà été reach et la mettre à ok.
    // soit ok w prev poids, soit pile right weight to reach 0, soit reste capa - weight plus grand 0 et peut se cumuler à capa prev
    if (tab[nbObject - 1][capacity] == 1) {
        printf("OUI\r\n");
    } else {
        printf("NON\r\n");
    }

    
    return 0;
}

/*#include <stdio.h>

int main(void) {
    int capacity;
    int objects[1000];
    int tmp_input = 0;
    objects[0] = 0;
    int nbObject = 1;

    scanf("%d", &capacity);

    while (tmp_input != -1) {
        scanf("%d", &tmp_input);
        if (tmp_input < 0) {
            continue;
        }
        objects[nbObject] = tmp_input;
        nbObject++;
    }

    int L[nbObject][capacity +1];
    L[0][0] = 1;
    int i;
    int j;
    for (i = 0; i < nbObject; i++) {
        L[i][0] = 1;
    }
    for (i = 1; i < capacity +1; i++) {
        L[0][i] = 0;
    }

    for (i = 1; i < nbObject; i++) {
        for (j = 1; j < capacity +1; j++) {
            L[i][j] = 0;
            if (L[i-1][j] == 1 || (j - objects[i] >= 0 && L[i-1][j - objects[i]] == 1) || j - objects[i] == 0) {
                L[i][j] = 1;
            }
        }
    }
    if (L[nbObject -1][capacity] == 1) {
        printf("OUI\r\n");
    } else {
        printf("NON\r\n");
    }
    return 0;
}*/