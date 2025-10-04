/*Question 19 Ecrire une fonction insertion permettant d’insérer un élement dans une dbl_list en
considerant que la liste passée en argument est ordonnée par ordre croissant, et de telle manière
à ce que la liste reste triée.*/

void push_dbllist(dbl_list *list, int val) {
    node *new_node = malloc(sizeof(node));
    new_node->val = val;

    if (!list->head) { // cas liste vide
        new_node->prev = new_node->next = NULL;
        list->head = new_node;
        return;
    }

    node *head = list->head;
    while (head->next && head->val < val)
        head = head->next;

    if (!head->prev && val < head->val) { // début
        new_node->prev = NULL;
        new_node->next = head;
        head->prev = new_node;
        list->head = new_node;
    } else if (!head->next && head->val < val) { // fin
        head->next = new_node;
        new_node->prev = head;
        new_node->next = NULL;
    } else { // milieu
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
    }
}

