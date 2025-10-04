#include <stdio.h>
#include <stdlib.h>

char **read_tab(int n) {
    int i, j;
    char **tab;
    tab = (char **)malloc(sizeof(char*) * n);
    for (i = 0; i < n; i++) {
        tab[i] = (char*)malloc(sizeof(char) * n);
        for (j = 0; j < n; j++) {
            tab[i][j] = getchar();
        }
        getchar(); // Lire le saut de ligne
    }
    return tab;
}

int main(void) {
    int n;
    char **tab;
    scanf("%d", &n);
    getchar(); // Lire le saut de ligne après l'entier
    
    tab = read_tab(n);
    
    // Vérifier les cases de départ et d'arrivée
    if (tab[0][0] == 'O' || tab[n-1][n-1] == 'O') {
        printf("0\r\n");
        return 0;
    }

    // Créer un tableau DP
    long long **dp = (long long **)malloc(sizeof(long long*) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = (long long *)malloc(sizeof(long long) * n);
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // Initialiser la première case
    dp[0][0] = 1;

    // Remplir le tableau DP
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tab[i][j] == 'O') continue;
            
            if (i > 0 && tab[i-1][j] == '+') 
                dp[i][j] += dp[i-1][j];
            if (j > 0 && tab[i][j-1] == '+') 
                dp[i][j] += dp[i][j-1];
        }
    }

    printf("%lld\r\n", dp[n-1][n-1]);
    // print dp 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lld ", dp[i][j]);
        }
        printf("\n");
    }

    // Libérer la mémoire
    for (int i = 0; i < n; i++) {
        free(tab[i]);
        free(dp[i]);
    }
    free(tab);
    free(dp);
    
    return 0;
}
