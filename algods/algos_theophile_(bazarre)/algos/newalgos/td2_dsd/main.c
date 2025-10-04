#include <stdio.h>

void selectionsort(int *tab, int size) {
    for (int i = 0; i < size; i++) {
        for (int k = i + 1; k < size; k++) {
            if (tab[k] < tab[i]) {
                int tmp = tab[i];
                tab[i] = tab[k];
                tab[k] = tmp;
            }
        }
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int tab[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }
    selectionsort(tab, n);

    if (n == 0) return 0;
    int res = tab[n - 2] - tab[1];

    printf("\n%d\r\n", res);
    return 0;
}