#include <stdio.h>

int main(void) {
    int tab[1000];
    int p = 0;
    while (p < 1000) {
        scanf("%d", &tab[p]);
        if (tab[p] == -1) {
            p--;
            break;
        };
        p++;
    }
    int i = 0, j = p;
    while (i < j) {
        if (tab[i] != tab[j]) {
            printf("0\r\n");
            return 0;
        }
        i++;
        j--;
    }
    printf("1\r\n");
    return 0;
}
