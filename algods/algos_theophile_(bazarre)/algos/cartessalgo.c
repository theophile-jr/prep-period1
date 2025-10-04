#include <stdio.h>

int main () {
    int num_cartes = 0;
    // line 1 = 2 = 3 mdr ;
    int m = 0;
    scanf("%d", &m);
    scanf("%d", &num_cartes);
    int cartes[1000];

    for (int i = 0; i < num_cartes; i++) {
        scanf("%d", &cartes[i]);
    }
    int res = 0;
    for (int i = 0; i < num_cartes; i++) {
        for (int j = i + 1; j < num_cartes; j++) {
            for (int k = j + 1; k < num_cartes; k++) {
                if ((cartes[i] + cartes[j] + cartes[k] == m)) {
                    res++;
                }
            }
        }
    }   
    printf("%d\r\n", res);
    return 0;
}
