#include <stdio.h>
#include <stdlib.h>

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

elem *list = NULL;

// Fonction helper pour ajouter en tête (utilisée dans le quicksort)
void ajouter_en_tete_helper(elem **head, int value) {
    elem *node = malloc(sizeof(elem));
    node->value = value;
    node->next = *head;
    *head = node;
}

// Fonction helper pour concaténer deux listes
void concatener_listes(elem **a, elem *b) {
    if (*a == NULL) {
        *a = b;
        return;
    }
    
    elem *current = *a;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = b;
}

// Quicksort pour listes chaînées (version préservant les nœuds)
elem *quicksort(elem *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    elem *inf_p = NULL, *sup_p = NULL;
    elem *inf_tail = NULL, *sup_tail = NULL;
    elem *current = head->next;
    int pivot = head->value;
    
    // Partitionner la liste
    while (current != NULL) {
        elem *next = current->next;
        current->next = NULL;
        
        if (current->value < pivot) {
            if (inf_p == NULL) {
                inf_p = current;
                inf_tail = current;
            } else {
                inf_tail->next = current;
                inf_tail = current;
            }
        } else {
            if (sup_p == NULL) {
                sup_p = current;
                sup_tail = current;
            } else {
                sup_tail->next = current;
                sup_tail = current;
            }
        }
        current = next;
    }
    
    // Trier récursivement les partitions
    elem *sorted_inf = quicksort(inf_p);
    elem *sorted_sup = quicksort(sup_p);
    
    // Reconnecter les listes triées avec le pivot
    head->next = sorted_sup;
    
    if (sorted_inf == NULL) {
        return head;
    } else {
        elem *tail = sorted_inf;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = head;
        return sorted_inf;
    }
}

// Fonction pour trier la liste (à appeler depuis le menu)
void trier_liste(void) {
    if (list == NULL) {
        printf("Liste vide, rien à trier.\n");
        return;
    }
    
    printf("Tri en cours...\n");
    list = quicksort(list);
    printf("Liste triée.\n");
}

void afficher(void) {
    elem *head = list;
    printf("Affichage liste : ");
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n------------\n");
}

void ajouter_en_tete(void) {
    int tmp;
    printf("Valeur à ajouter: ");
    scanf("%d", &tmp);
    elem *node = malloc(sizeof(elem));
    node->value = tmp;
    node->next = list;
    list = node;
}

void rechercher(void) {
    int goal;
    printf("Valeur à rechercher: ");
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
    printf("Pas trouvé\n");
}

void supprimer() {
    int tmp = 0;
    printf("Valeur à supprimer: ");
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
    printf("Valeur à ajouter: ");
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
    printf("Valeur à dupliquer: ");
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
    printf("Valeur à ajouter: ");
    scanf("%d", &tmp);
    
    elem *nouveau = malloc(sizeof(elem));
    nouveau->value = tmp;
    nouveau->next = NULL;
    
    if (list == NULL) {
        list = nouveau;
        return;
    }
    
    if (tmp <= list->value) {
        nouveau->next = list;
        list = nouveau;
        return;
    }
    
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
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    list = prev;
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
        printf("\t10: trier (quicksort)\n");
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
        case 10:
            trier_liste();
            break;
        default:
            printf("choix incorrect\n");
            continue;
        }
    }
fin:
    // Libérer la mémoire avant de quitter
    elem *current = list;
    while (current != NULL) {
        elem *temp = current;
        current = current->next;
        free(temp);
    }
    printf("au revoir\n");
    return 0;
}