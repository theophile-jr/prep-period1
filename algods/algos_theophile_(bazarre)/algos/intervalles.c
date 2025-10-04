#include <stdio.h>

int main(void) {
    double a1, b1;
    double a2, b2;
    double gauche, droite;
    double aire;
    scanf("%lf", &a1);
    scanf("%lf", &b1);
    scanf("%lf", &a2);
    scanf("%lf", &b2);

    gauche = (a1 > a2) ? a1 : a2;
    droite = (b1 < b2) ? b1 : b2;
    aire = (droite >= gauche) ? droite - gauche : 0;
    printf("%.0lf\r\n", aire);
    return 0;

}