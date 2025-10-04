#include <stdio.h>

void displayfile(char *path) {
}

// int main () {
//     FILE *file = fopen("q9.txt", "w+");
//     while (fgetc(stdin) != 'q') {
//         while (!feof(file)) {
//             if (fgetc(file) == EOF) break;
//             char c = fgetc(file);
//             fputc(c, stdout);
//         }
//         rewind(file); // fini afficher
//     char k;
//     while (1) {
//         k = fgetc(stdin);
//         if   (k)
//             break;
//     }
//     int offset;
//     scanf("%d", &offset);
//     fseek(file, offset, k); // positionne le curseur a l'offset

//     for (int i = 0; i < 20; i++) {
//         for (int i2 = 0; i2 < 40; i2++) {
//             fputc('_', file);
//         }
//         fputc('\n', file);
//     }
//     }
//     rewind(file); 
//     // fseek(file, 0, SEEK_SET); (0 = offset pour b ouger), seek_set = position direct // possible aussi : fseek(file, 0, SEEK_END); (pour aller a la fin)
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("q9.txt", "w+");
    
    // Créer le fichier UNE SEULE FOIS au début
    for (int i = 0; i < 20; i++) {
        for (int i2 = 0; i2 < 40; i2++) {
            fputc('_', file);
        }
        fputc('\n', file);
    }
    
    char k; 
    int offset;
    
    do {
        // Afficher le fichier
        rewind(file);
        int c;
        while ((c = fgetc(file)) != EOF) {
            fputc(c, stdout);
        }
        
        // Lire les entrées
        printf("\nCaractère (q=quitter): ");
        scanf(" %c", &k);
        if (k == 'q') break;
        
        printf("Offset: ");
        scanf("%d", &offset);
        
        // Remplacer le caractère
        fseek(file, offset, SEEK_SET);
        if (fgetc(file) == '\n') offset++;
        fseek(file, offset, SEEK_SET);
        //  FGETS INTERESSANT 
        fputc(k, file);
        fflush(file); // important pour écrire tout de suite
        
    } while (k != 'q');
    
    fclose(file);
    return 0;
}
/*
✅ Les modes de base

"r" → lecture seule (read). Le fichier doit exister.

"w" → écriture seule (write). Si le fichier existe → il est écrasé. Sinon → il est créé.

"a" → ajout (append). Si le fichier existe → on écrit à la fin. Sinon → il est créé.

✅ Modes en lecture/écriture

"r+" → lecture et écriture. Le fichier doit exister.

"w+" → lecture et écriture. Le fichier est écrasé s’il existe, sinon créé.

"a+" → lecture et écriture. On écrit toujours à la fin du fichier, mais on peut lire le contenu existant.
*/