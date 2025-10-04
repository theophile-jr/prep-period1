#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main () {
    srand((unsigned) time(NULL));
    int hauteur = rand() % 50;
    int tronc = rand() % 10;
    int largeur_tronc = hauteur / 7;
    int y_boule = rand() % hauteur;

    int placed_boule = 0;
    char ligne[1000] = "*\0";
    int inverse_hauteur = hauteur - 1;
    int last_size = 0;
    int xboule = 0;


    for (int i = 0 ; i < hauteur; i++) {
        if (placed_boule == 0 && y_boule == i) {
            xboule = (rand() % strlen(ligne)) + inverse_hauteur;
            ligne[xboule] = 'O';
            placed_boule = 1;
            placed_boule = 1;
        }
        printf("%*s\n", inverse_hauteur + strlen(ligne), ligne);
        if (placed_boule == 1)
            ligne[xboule] = '*';
        inverse_hauteur--;
        if (i == hauteur - 1){
            last_size = strlen(ligne);
        } 
        strncat(ligne, strdup("**"), 2);

    }
    for (int i = 0; i < tronc; i++) {
        char ligne[largeur_tronc];
        ligne[0] = '\0';
        while (strlen(ligne) < largeur_tronc) strncat(ligne, strdup("|"), 1);
        printf("%*s\n", (last_size + largeur_tronc)/2, ligne);
    }
}
