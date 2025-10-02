#include <stdio.h>

void bubbleSort(int *tab, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                int tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int nb[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &nb[i]);
    }
    bubbleSort(nb, n);
    int diametreRelatif = nb[n-2] - nb[1];

    printf("%d\r\n", diametreRelatif);

    return 0;
}