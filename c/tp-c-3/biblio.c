int somme (int *tab, int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += tab[i];
    }
    return res;
}

int moyen (int *tab, int size) {
    return somme(tab, size) / size;
}

int produit (int *tab, int size) {  
    int res = 1;
    for (int i = 0; i < size; i++) {
        res *= tab[i];
    }
    return res;
}

int min (int *tab, int size) {
    int min = tab[0];
    for (int i = 1; i < size; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
    }
    return min;
}

int max (int *tab, int size) {
    int max = tab[0];
    for (int i = 1; i < size; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
}
