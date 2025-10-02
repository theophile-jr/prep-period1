#include <stdio.h>

int main(void) {
    int capacity;
    int weights[1000];
    int tmp_input = 0;
    int nbObject = 0;

    // tmp_input
    scanf("%d", &capacity);

    while (tmp_input != -1) {
        scanf("%d", &tmp_input);
        if (tmp_input < 0) {
            continue;
        }
        weights[nbObject] = tmp_input;
        nbObject++;
    }

    // START OF THE ALGORITHM
    int L[capacity +1];             // +1 car capacity 0 doit avoir un tab de taille 1
    L[0] = 1;

    int j;
    int o;

    // start j = 1 beacause L[0] == 1
    for(j = 1; j <= capacity; j++) {
        L[j] = 0;
        for(o = 0; o < nbObject; o++) {
            // in this case skip
            if(j-weights[o] < 0) continue;

            if(L[j-weights[o]] == 1) {
                L[j] = 1;
                break;                  //we don't want to earase previous results
            }
        }
    }


    if(L[capacity] == 1) {
        printf("OUI\r\n");
    } else {
        printf("NON\r\n");
    }

    return 0;
}