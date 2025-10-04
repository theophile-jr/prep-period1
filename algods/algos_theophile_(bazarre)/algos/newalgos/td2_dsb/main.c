#include <stdio.h>

int main () {
    int m;
    int n;
    int count = 0;
    scanf("%d", &m);
    scanf("%d", &n);
    int cartes[n];
    for (int i = 0 ; i < n; i++) {
        scanf("%d", &cartes[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("[[%d]]", cartes[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int i2 = i + 1; i2 < n; i2++) {
            for (int i3 = i2 + 1; i3 < n; i3++) {
                if ((cartes[i] + cartes[i2] + cartes[i3]) == m) {
                    count++;
                }
            }
        }
    }
    printf("%d\r\n", count);
    return 0;
}
