#include <stdio.h>

int main () {
    int capacity;
    int nbobjet; 

    scanf("%d", &capacity);
    scanf("%d", &nbobjet);
    int weight_store[nbobjet];
    int colors_store[nbobjet];
    int dp[capacity+1];
    for (int i = 0; i < nbobjet; i++) {
        scanf("%d %d", &colors_store[i], &weight_store[i]);
    }
    dp[0] = 0;
    for (int i = 1; i <= capacity; i++) {
        dp[i] = -1;
    }
    for (int obji = 0; obji < nbobjet; obji++) {
        for (int capaci = capacity; capaci >= weight_store[obji]; capaci--) {
            if (dp[capaci - weight_store[obji]] >= 0) {
                int isgreen = (colors_store[obji] == 1);
                int prev = dp[capaci - weight_store[obji]];
                int wobj = prev + isgreen;
                if (dp[capaci] == -1) {
                    dp[capaci] = wobj;
                } else {
                    if (wobj < dp[capaci])
                        dp[capaci] = wobj;
                }


            }
        }
    }
    printf("%d\r\n", dp[capacity]);
    return 0;
}