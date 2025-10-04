#include <stdio.h>

int main() {
    int val = 1000;

    if (val == 1000) {
        printf("Vous êtes dans le mille!\n");
    } 
    else if (val > 10000) {
        printf("Valeur beaucoup trop grande\n");
    } 
    else if (val > 1000) {
        printf("Valeur trop grande\n");
    } 
    else if (val < 100) {
        printf("Valeur beaucoup trop petite\n");
    } 
    else if (val < 1000) {
        printf("Valeur trop petite\n");
    }

    return 0;
}

