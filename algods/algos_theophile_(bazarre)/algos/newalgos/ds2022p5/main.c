#include <stdio.h>

int main () {
    int capacity;
    int pa;
    int po;

    scanf("%d", &capacity);
    scanf("%d", &pa);
    scanf("%d", &po);

    int nombre_objets = po + pa;
    int objets[nombre_objets];
    int dp[capacity + 1];

    for (int i = 0; i < nombre_objets; i++) {
        scanf("%d", &objets[i]);
    }
    dp[0] = 1;
    for (int i = 1 ; i <= capacity; i++) dp[i] = 0;

    for (int i = 0; i < nombre_objets; i++) {
        if (objets[i] >= 50) continue;
        for (int i2 = capacity; i2 >= objets[i]; i2--) {
            if (dp[i2 - objets[i]] == 1) {
                dp[i2] = 1;
            }
        }
    }
    

    int i = capacity;
    while (dp[i] == 0) {
        i--;
    }

    printf("%d\r\n", i);
}