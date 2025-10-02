#include <stdio.h>

int main(void) {
    int capacity, nbChevresArdeche, nbChevresDrome;
    scanf("%d", &capacity);
    scanf("%d", &nbChevresArdeche);
    scanf("%d", &nbChevresDrome);

    int poids[100];

    int i;
    for (i = 0; i < nbChevresArdeche + nbChevresDrome; i++) {
        scanf("%d", &poids[i]);
    }

    int dp[1201] = {0};
    dp[0] = 1;

    int p;
    for (i = 0; i < nbChevresArdeche + nbChevresDrome; i++) {
        if (poids[i] <= 50) {
            for (p = capacity; p >= poids[i]; p--) {
                if (dp[p - poids[i]] == 1) {
                    dp[p] = 1;
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
