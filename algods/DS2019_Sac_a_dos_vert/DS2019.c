#include <stdio.h>

#define INF 999999999

int main() {
    int capacity, nbObjects;
    scanf("%d", &capacity);
    scanf("%d", &nbObjects);

    int colors[1000], weights[1000];
    int i;
    for (i = 0; i < nbObjects; i++) {
        scanf("%d %d", &colors[i], &weights[i]);
    }

    int minVert[1000];
    for (i = 0; i <= capacity; i++) minVert[i] = INF;
    minVert[0] = 0;

    int w;
    for (i = 0; i < nbObjects; i++) {
        for (w = capacity; w >= weights[i]; w--) {
            if (minVert[w - weights[i]] != INF) {
                int isGreen = (colors[i] == 1 ? 1 : 0);
                if (minVert[w - weights[i]] + isGreen < minVert[w]) {
                    minVert[w] = minVert[w - weights[i]] + isGreen;
                }
            }
        }
    }

    if (minVert[capacity] == INF) {
        printf("-1\r\n");
    } else {
        printf("%d\r\n", minVert[capacity]);
    }

    return 0;
}