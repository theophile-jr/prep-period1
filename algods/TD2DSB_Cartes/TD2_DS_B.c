#include <stdio.h>

int main(void) {
    int M,N;
    scanf("%d", &M);
    scanf("%d", &N);
    int cartes[N];
    int i;
    for(i=0;i<N;i++) {
        scanf("%d", &cartes[i]);
    }
    int nbSolutions = 0;
    int j, k;
    for(i=0;i<N;i++) {
        for(j=i+1;j<N;j++) {
            for(k=j+1;k<N;k++) {
                if(cartes[i]+cartes[j]+cartes[k]==M) {
                    nbSolutions++;
                }
            }
        }
    }
    printf("%d\r\n", nbSolutions);
    return 0;
}