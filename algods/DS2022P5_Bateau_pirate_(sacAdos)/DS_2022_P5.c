#include <stdio.h>

int main(void) {

    int capacity;
    scanf("%d", &capacity);
    int nbObjets, nbArgent, nbOr;
    scanf("%d", &nbArgent);
    scanf("%d", &nbOr);

    nbObjets = nbArgent + nbOr;

    int objets[nbObjets];
    int i;
    for (i = 0; i < nbObjets; i++) {
        scanf("%d", &objets[i]);
    }

    int dp[capacity + 1];
    dp[0] = 1;
    for (i = 1; i <= capacity; i++) {
        dp[i] = 0;
    }
    for (i = 0; i < nbObjets; i++) {
        if (objets[i] < 50) {
            int o;
            for (o = capacity; o >= objets[i]; o--) {
                if (dp[o - objets[i]] == 1) {
                    dp[o] = 1;
                }
            }
        }
    }

    int maxPoids = 0;
    for (i = capacity; i >= 0; i--) {
        if (dp[i] == 1) {
            maxPoids = i;
            break;
        }
    }

    printf("%d\r\n", maxPoids);

    return 0;
}