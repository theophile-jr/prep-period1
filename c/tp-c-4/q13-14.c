// Fgets stops at \0 or \n or max size read -1


// Q14

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_LIGNE 256

void afficher_ligne_aleatoire_simple(const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur: impossible d'ouvrir %s\n", nom_fichier);
        return;
    }

    // Compter le nombre de lignes
    int nb_lignes = 0;
    char ligne[TAILLE_LIGNE];
    while (fgets(ligne, TAILLE_LIGNE, fichier) != NULL) {
        nb_lignes++;
    }
    
    if (nb_lignes == 0) {
        printf("Fichier %s vide\n", nom_fichier);
        fclose(fichier);
        return;
    }
    
    // Choisir une ligne aléatoire
    int ligne_choisie = random() % nb_lignes;
    
    // Relire le fichier pour aller à la ligne choisie
    rewind(fichier);
    int ligne_courante = 0;
    while (fgets(ligne, TAILLE_LIGNE, fichier) != NULL) {
        if (ligne_courante == ligne_choisie) {
            // Supprimer le saut de ligne et afficher
            ligne[strcspn(ligne, "\n")] = 0;
            printf("%s\n", ligne);
            break;
        }
        ligne_courante++;
    }
    
    fclose(fichier);
}

int main() {
    srandom(time(NULL));
    
    for (int i = 1; i <= 4; i++) {
        char nom_fichier[20];
        sprintf(nom_fichier, "colonne%d.txt", i);
        afficher_ligne_aleatoire_simple(nom_fichier);
    }
    
    return 0;
}