#include <stdio.h>

int main () {
    int size; 
    int values[10000];
    int average = 0;
    int res = 0;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &values[i]); //check what typeof btw
    }
    for (int i = 0; i < size; i++) {
        average += values[i];
    }
    if (size == 0) {
        printf("0\r\n");
        return 0;
    }
    average /= size;

    for (int i = 0; i < size; i++ ) {
        if (values[i] > 0 && values[i] >= average) {
            res++;
        }
    }
    printf("%d\r\n", res);
    return 0;
}