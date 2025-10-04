#include <stdio.h>

int main () {
    int v [ ] = { 1, 2, 3, 4 };
    int *pt = v;
    *pt++ = 9;
    // int x = pt[ -1 ];

    for (int i = 0; i < 4; i++) {
        printf ("%d ", v [i]);
    }
    printf ("\n");
}