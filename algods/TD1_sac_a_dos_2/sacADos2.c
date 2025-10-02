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
    // for (int i = 0; i < nbObject; i++) {
    //     for (int j = 0; j < capacity +1; j++) {
    //         printf("%d ", L[i][j]);
    //     }
    //     printf("\r\n");
    // }
    return 0;
}