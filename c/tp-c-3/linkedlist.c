typedef struct _elem
{
    int value;
    struct _elem *next;
} elem;

typedef struct _treenode
{
    int value;
    struct _treenode *left;
    struct _treenode *right;
} treenode;

#include <stdio.h>
#include <stdlib.h>

elem *list = NULL;


void afficher(void) {
    elem *head = list;
    printf("Affichage liste : ");
    while (head != NULL) {
        printf("%d\n", head->value);
        head = head->next;
    }
    printf("------------\n");
}

void ajouter_en_tete(void) {
    int tmp;
    scanf("%d", &tmp);
    elem *node = malloc(sizeof(elem));
    node->value = tmp;
    if (list == NULL) {
        list = node;
        node->next = NULL;
    } else {
        node->next = list;
        list = node;
    }
}

void rechercher(void) {
    int goal;
    scanf("%d", &goal);

    int index = 0;
    elem *head = list;
    while (head != NULL) {
        if (head->value == goal) {
            printf("Position pour la valeur = %d\n", index);
            return;
        }
        index++;
        head = head->next;
    }
    printf("Pas trouvé");
}

void supprimer() {
    int tmp = 0;
    scanf("%d", &tmp);
    
    elem *prev = NULL;
    elem *current = list;
    
    while (current != NULL) {
        if (current->value == tmp) {
            elem *toDelete = current;
            
            if (prev == NULL) {
                list = current->next;
                current = list; 
            } else {
                prev->next = current->next;
                current = current->next;
            }
            free(toDelete);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void ajouter_en_queue(void) {
    int tmp = 0;
    scanf("%d", &tmp);
    elem *node = malloc(sizeof(elem));
    node->value = tmp;
    node->next = NULL;
    elem *current = list;
    if (list == NULL) {
        list = node;
    } else {
        while  (current->next != NULL) current = current->next;
        current->next = node;
    }
    
}

void dupliquer(void) {
    int tmp = 0;
    scanf("%d", &tmp);

    elem *current = list;

    while (current != NULL) {
        if (current->value == tmp) {
            elem *nouveau = malloc(sizeof(elem));
            nouveau->value = tmp;
            nouveau->next = current->next;
            current->next = nouveau;
            current = nouveau->next;
        } else {
            current = current->next;
        }
    }
}

void ajouter_en_place(void) {
    int tmp;
    scanf("%d", &tmp);
    
    elem *nouveau = malloc(sizeof(elem));
    nouveau->value = tmp;
    nouveau->next = NULL;
    
    // Cas 1: liste vide
    if (list == NULL) {
        list = nouveau;
        return;
    }
    
    // Cas 2: insertion en tête
    if (tmp <= list->value) {
        nouveau->next = list;
        list = nouveau;
        return;
    }
    
    // Cas 3: insertion au milieu ou fin
    elem *current = list;
    while (current->next != NULL && current->next->value < tmp) {
        current = current->next;
    }
    
    nouveau->next = current->next;
    current->next = nouveau;
}

void retourner(void) {
    elem *prev = NULL;
    elem *current = list;
    elem *next = NULL;
    
    while (current != NULL) {
        next = current->next;  // Sauvegarder le suivant
        current->next = prev;  // Inverser le lien
        prev = current;        // Avancer prev
        current = next;        // Avancer current
    }
    
    list = prev;  // Nouvelle tête est l'ancienne fin
}

void is_triee(void) {
    if (list == NULL) {
        printf("Oui\n");
        return;
    }

    elem *head = list;
    int val = head->value;
    head = head->next;

    while (head != NULL) {
        if (head->value < val) {
            printf("Non\n");
            return;
        }
        val = head->value;
        head = head->next;
    }
    printf("Oui\n");
}

int main(void)
{
    while (1)
    {
        printf("menu:\n");
        printf("\t1: ajouter en tete\n");
        printf("\t2: afficher la liste\n");
        printf("\t3: rechercher\n");
        printf("\t4: ajouter_en_queue\n");
        printf("\t5: supprimer\n");
        printf("\t6: dupliquer\n");
        printf("\t7: is_triee\n");
        printf("\t8: ajouter en place\n");
        printf("\t9: retourner\n");
        printf("\t0: quitter\n");
        int choix;
        scanf("%d", &choix);
        switch (choix)
        {
        case 0:
            goto fin;
        case 1:
            ajouter_en_tete();
            break;
        case 2:
            afficher();
            break;
        case 3:
            rechercher();
            break;
        case 4:
            ajouter_en_queue();
            break;
        case 5:
            supprimer();
            break;
        case 6:
            dupliquer();
            break;
        case 7:
            is_triee();
            break;
        case 8:
            ajouter_en_place();
            break;
        case 9: 
            retourner();
            break;
        default:
            printf("choix incorrect\n");
            continue;
        }
    }
fin:
    printf("au revoir\n");
    return 0;
}