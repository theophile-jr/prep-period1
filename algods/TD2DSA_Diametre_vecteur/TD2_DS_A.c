#include <stdio.h>
#define INF 100000

int main(void) {
    int nbVal;
    scanf("%d", &nbVal);
    int val[nbVal];
    int i;
    for (i = 0; i < nbVal; i++) {
        scanf("%d", &val[i]);
    }
    int max = val[0];
    int min = val[0];
    int maxNeg = -INF;
    int minPos = INF;
    for (i = 0; i < nbVal; i++) {
        if (val[i] > max) {
            max = val[i];
        }
        if (val[i] < min) {
            min = val[i];
        }
        if (val[i] < 0 && val[i] > maxNeg) {
            maxNeg = val[i];
        }
        if (val[i] > 0 && val[i] < minPos) {
            minPos = val[i];
        }
    }
    //printf("%d\r\n", max);
    //printf("%d\r\n", min);
    //printf("%d\r\n", maxNeg);
    //printf("%d\r\n", minPos);
    int rayonVecteur = max - min;
    int rayonCentroide = minPos - maxNeg;
    //printf("%d\r\n", rayonVecteur);
    //printf("%d\r\n", rayonCentroide);
    printf("%d\r\n", rayonVecteur - rayonCentroide);
    return 0;
}