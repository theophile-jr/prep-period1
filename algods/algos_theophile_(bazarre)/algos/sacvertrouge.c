#include <stdio.h>

#define MAX_C 1000

/* donc en gros chaque case != -1 veut dire que la valeur est atteignable et contient donc le nombre d'objet verts qu'il faut pour l'atteindre. donc quand on trouve qu'une case est atteignable, on vient prendre le nombnre d'objet vert de la case précédente et on cumule progrissvmeent. et si mieux que avant (donc si pas possible mieux), si inférieur à valeur possible, alors on la met dans la cacse. 
et on check last case, becacuse we want to reach the end anyway
*/

int main() {
    int C, n;
    scanf("%d", &C);
    scanf("%d", &n);

    int dp[MAX_C + 1];
    for (int i = 1; i <= C; i++) dp[i] = -1;
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int color, weight;
        scanf("%d %d", &color, &weight);
        
        for (int j = C; j >= weight; j--) {
            if (dp[j - weight] != -1) {
                int new_val = dp[j - weight] + (color == 1);
                if (dp[j] == -1 || new_val < dp[j]) 
                    dp[j] = new_val;
            }
        }
    }
    
    printf("%d\r\n", dp[C]);
    return 0;
}
