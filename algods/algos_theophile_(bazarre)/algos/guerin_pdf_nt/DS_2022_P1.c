#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int entiers[n];
    int i;
    int nbPair = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &entiers[i]);
        if (entiers[i] % 2 == 0) {
            nbPair++;
        }
    }
    if (nbPair > (double)n / 2) {
        printf("P\r\n");
    } else if (nbPair < (double)n / 2) {
        printf("I\r\n");
    } else {
        printf("\r\n");
    }
    return 0;
}