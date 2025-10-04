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

    int dp[1201];
    for (i = 0; i <= capacity; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    int p;
    for (i = 0; i < nbChevresArdeche + nbChevresDrome; i++) {
        for (p = capacity; p >= poids[i]; p--) {
            if (poids[i] < 50 && dp[p - poids[i]] == 1) {
                dp[p] = 1;
            }
        }
    }

    i = capacity;
    while (dp[i] == 0) {
        i--;
    }

    printf("%d\r\n", i);



    return 0;


}