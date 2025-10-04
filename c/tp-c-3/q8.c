#include <stdio.h>

typedef struct personne_s {
    char name[100];
    char *numero[100];
} personne_t;

int main () {
    personne_t personnes[10];
    for (int i = 0; i < 10; i++) {
        scanf("%s", &personnes[i].name);
        scanf("%s", &personnes[i].numero);
    }
    for (int i = 0; i < 10; i++) {
        printf("%s -> %s\n", personnes[i].name, personnes[i].numero);
    }

return 0;
}
