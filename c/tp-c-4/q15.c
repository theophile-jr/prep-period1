#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAILLE_LIGNE 256
#define NB_PHRASES 5

// Fonction pour lire une ligne aléatoire d'un fichier
char* lire_ligne_aleatoire(const char *nom_fichier, char *buffer) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur: impossible d'ouvrir %s\n", nom_fichier);
        return NULL;
    }

    // Compter le nombre de lignes
    int nb_lignes = 0;
    char ligne_temp[TAILLE_LIGNE];
    while (fgets(ligne_temp, TAILLE_LIGNE, fichier) != NULL) {
        nb_lignes++;
    }
    
    if (nb_lignes == 0) {
        printf("Fichier %s vide\n", nom_fichier);
        fclose(fichier);
        return NULL;
    }
    
    // Choisir une ligne aléatoire
    int ligne_choisie = random() % nb_lignes;
    
    // Relire le fichier pour aller à la ligne choisie
    rewind(fichier);
    int ligne_courante = 0;
    while (fgets(ligne_temp, TAILLE_LIGNE, fichier) != NULL) {
        if (ligne_courante == ligne_choisie) {
            // Supprimer le saut de ligne et copier dans le buffer
            ligne_temp[strcspn(ligne_temp, "\n")] = 0;
            strcpy(buffer, ligne_temp);
            fclose(fichier);
            return buffer;
        }
        ligne_courante++;
    }
    
    fclose(fichier);
    return NULL;
}

int main() {
    srandom(time(NULL)); // initialisation de la graine d'aléa
    
    // Ouvrir le fichier de sortie
    FILE *discours = fopen("discours.txt", "w");
    if (discours == NULL) {
        printf("Erreur: impossible de créer discours.txt\n");
        return 1;
    }
    
    char phrase[TAILLE_LIGNE];
    
    // Générer 5 phrases
    for (int i = 0; i < NB_PHRASES; i++) {
        // Construire une phrase avec une ligne de chaque colonne
        char phrase_complete[TAILLE_LIGNE * 4] = "";
        
        for (int col = 1; col <= 4; col++) {
            char nom_fichier[20];
            sprintf(nom_fichier, "colonne%d.txt", col);
            
            if (lire_ligne_aleatoire(nom_fichier, phrase) != NULL) {
                strcat(phrase_complete, phrase);
                strcat(phrase_complete, " ");
            }
        }
        
        // Écrire la phrase dans le fichier
        fprintf(discours, "%s.\n", phrase_complete);
    }
    
    fclose(discours); // N'oubliez pas de fermer le fichier
    printf("Discours généré dans discours.txt\n");
    
    return 0;
}


// q16
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;
    
    struct stat st;
    if (stat(argv[1], &st) == -1) return 1;
    
    printf("Droits propriétaire %s:\n", argv[1]);
    printf("- Lecture: %s\n", (st.st_mode & S_IRUSR) ? "OUI" : "NON");
    printf("- Écriture: %s\n", (st.st_mode & S_IWUSR) ? "OUI" : "NON");
    printf("- Exécution: %s\n", (st.st_mode & S_IXUSR) ? "OUI" : "NON");
    
    return 0;
}