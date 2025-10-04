#include <stdio.h>
#include <stdlib.h>

// =======================================================================
//                           STRUCTURES
// =======================================================================

typedef struct node {
    int val;
    struct node *prev;
    struct node *next;
} node;

typedef struct dbl_list {
    node *head;
} dbl_list;

// =======================================================================
//                        FONCTIONS UTILITAIRES
// =======================================================================

node* create_node(int val) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void print_list(const dbl_list *list) {
    if (list == NULL || list->head == NULL) {
        printf("Liste vide.\n");
        return;
    }
    
    node *current = list->head;
    printf("Liste (HEAD -> TAIL): ");
    while (current != NULL) {
        printf("%d <-> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(dbl_list *list) {
    node *current = list->head;
    node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}

// =======================================================================
//                       FONCTIONS D'INSERTION (PUSH)
// =======================================================================

void push_head(dbl_list *list, int val) {
    node *new_node = create_node(val);

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
}

void push_tail(dbl_list *list, int val) {
    node *new_node = create_node(val);

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    new_node->prev = current;
}

int push_at_index(dbl_list *list, int val, int index) {
    if (index < 0) return 0;

    if (index == 0) {
        push_head(list, val);
        return 1;
    }

    node *current = list->head;
    int i = 0;
    
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        if (i == index && i > 0) {
            push_tail(list, val);
            return 1;
        }
        return 0;
    }
    
    node *new_node = create_node(val);

    new_node->next = current;
    new_node->prev = current->prev;
    
    if (current->prev != NULL) {
        current->prev->next = new_node;
    }
    current->prev = new_node;
    
    return 1;
}

void push_dbllist(dbl_list *list, int val) {
    node *new_node = create_node(val);

    if (!list->head) { 
        list->head = new_node;
        return;
    }

    node *head = list->head;
    while (head->next != NULL && head->val < val) {
        head = head->next;
    }

    if (!head->prev && val < head->val) {
        new_node->next = head;
        head->prev = new_node;
        list->head = new_node;
    } 
    else if (!head->next && head->val < val) {
        head->next = new_node;
        new_node->prev = head;
        new_node->next = NULL;
    } 
    else {
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
    }
}

// =======================================================================
//                       FONCTIONS DE SUPPRESSION (REMOVE)
// =======================================================================

int remove_head(dbl_list *list, int *value) {
    if (list->head == NULL) {
        return 0;
    }

    node *temp = list->head;
    *value = temp->val;
    
    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    }
    
    free(temp);
    return 1;
}

int remove_tail(dbl_list *list, int *value) {
    if (list->head == NULL) {
        return 0;
    }

    if (list->head->next == NULL) {
        return remove_head(list, value);
    }

    node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    *value = current->val;
    
    current->prev->next = NULL; 
    free(current);
    return 1;
}

int remove_at_index(dbl_list *list, int index, int *value) {
    if (list->head == NULL || index < 0) {
        return 0;
    }
    
    if (index == 0) {
        return remove_head(list, value);
    }

    node *current = list->head;
    int i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        return 0;
    }

    *value = current->val;
    
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    return 1;
}

// =======================================================================
//                                MAIN DE DÉMONSTRATION
// =======================================================================

int main() {
    dbl_list ma_liste = { .head = NULL };
    int val_removed = 0;

    printf("--- 1. DEMO D'INSERTION CLASSIQUE ---\n");
    push_head(&ma_liste, 20);
    push_tail(&ma_liste, 40);
    push_head(&ma_liste, 10);
    push_tail(&ma_liste, 50);
    printf("Après push_head(10, 20) et push_tail(40, 50):\n");
    print_list(&ma_liste); 

    push_at_index(&ma_liste, 30, 2);
    printf("\nAprès push_at_index(30, index 2):\n");
    print_list(&ma_liste); 

    // Test de l'insertion triée
    push_dbllist(&ma_liste, 25);
    push_dbllist(&ma_liste, 5);
    printf("\nAprès push_dbllist(25, 5) (tri):\n");
    print_list(&ma_liste); 
    
    printf("\n--- 2. DEMO DE SUPPRESSION ---\n");

    // Suppression en tête
    if (remove_head(&ma_liste, &val_removed)) {
        printf("remove_head: %d\n", val_removed);
    }
    print_list(&ma_liste); 

    // Suppression en queue
    if (remove_tail(&ma_liste, &val_removed)) {
        printf("remove_tail: %d\n", val_removed);
    }
    print_list(&ma_liste); 

    // Suppression par index (index 1 = 20)
    if (remove_at_index(&ma_liste, 1, &val_removed)) {
        printf("remove_at_index(1): %d\n", val_removed);
    }
    print_list(&ma_liste); 

    printf("\n--- 3. NETTOYAGE ---\n");
    free_list(&ma_liste);
    printf("Liste après free_list:\n");
    print_list(&ma_liste);

    return 0;
}