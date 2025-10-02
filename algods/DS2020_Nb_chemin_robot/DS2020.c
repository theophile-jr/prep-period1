#include <stdio.h>
#include <stdlib.h>

char ** read_tab(int n) {
    int i,j;
    char ** tab;
    tab = (char **) malloc(sizeof(char*)*n);
    for (i=0;i<n;i++) {
        tab[i] = (char*) malloc(sizeof(char)*n);
        for (j=0;j<n;j++) {
            tab[i][j] = getchar();
        }
        getchar(); // consomme le '\n' de fin de ligne
    }
    return tab;
}

int main(void) {
    int n, i, j;
    char ** tab;
    int *nbChemins;   // nbChemins[j] = nb de chemins pour atteindre la case (i,j) tab unidim pour opti la memory
    int npossibilites;

    if (scanf("%d",&n) != 1) return 0;
    getchar();
    tab = read_tab(n);

    nbChemins = (int*) calloc(n, sizeof(int)); // calloc = malloc + init à 0
    if (!nbChemins) return 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (tab[i][j] == 'O') {
                nbChemins[j] = 0;
            } else if (i == 0 && j == 0) {
                nbChemins[0] = 1;
            } else {
                int from_top = nbChemins[j];
                int from_left = (j > 0) ? nbChemins[j-1] : 0;
                nbChemins[j] = from_top + from_left;
            }
        }
    }

    npossibilites = nbChemins[n-1];

    printf("%d\r\n", npossibilites);

    free(nbChemins);
    for (i = 0; i < n; i++) free(tab[i]);
    free(tab);

    return 0;
}