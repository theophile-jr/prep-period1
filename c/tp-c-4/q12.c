#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f = fopen("fichier.txt", "w+");
    if (f == NULL) {
        perror("Erreur ouverture fichier");
        return 1;
    }
    
    // Allouer buffer dynamiquement
    fseek(f, 0, SEEK_END);
    long taille = ftell(f);
    rewind(f);
    
    char *buffer = malloc(taille + 1);
    fread(buffer, 1, taille, f);
    buffer[taille] = '\0';
    fclose(f);
    
    char k;
    long offset;
    char input[100];
    
    do {
        // Afficher le buffer
        printf("%s\n", buffer);
        
        printf("Caractère (q=quitter): ");
        fgets(input, sizeof(input), stdin);
        k = input[0];
        if (k == 'q') break;
        
        printf("Offset: ");
        fgets(input, sizeof(input), stdin);
        offset = atol(input);
        
        // Modifier le buffer en mémoire
        if (offset >= 0 && offset < taille) {
            buffer[offset] = k;
        }
        
    } while (k != 'q');
    
    // Sauvegarder à la fin
    f = fopen("fichier.txt", "w");
    fwrite(buffer, 1, taille, f); // (wirting 1octet for char * taille)
    fclose(f);
    
    free(buffer);
    return 0;
}