#include <stdio.h>

// q1 2 3 
// int main () {
//     double variable = 13.12;
//     double *ptr_d = &variable;
//     *(ptr_d) = 7; // changing variable's value through it's pointer
//     printf("variable value = %f ;  available at %p ; ptr_d value = %f and it's adress : %p", variable, &variable, *ptr_d, &ptr_d);
// }




// q4
// int main () {
//     int *ptr;
//     printf("%d", *ptr);
// } // -> on peut voir que si le pointeur n'a pas d'adresse alors dans ce cas là on a une valeur aléatoire qui s'affiche à l'écran 
// // -> should be a segfault

// q5
// int main () {
//     float f = 3.2;
//     float *ptr_f = &f;
//     printf("sizeof f : %zd sizeof ptr_f %zd", sizeof(f), sizeof(ptr_f));
//     // 4 is the size of the flaot, 8 is the size of the ptr
// }

// q6
// int main () {
//     float f = 3.2;
//     void *ptr_f = &f;
//     printf("sizeof f : %zd sizeof ptr_f %zd", sizeof(f), sizeof(ptr_f));
//     // 4 is the size of the flaot, 8 is the size of the ptr
// }

// q7
// int main () { 
//     int tab[10];
//     printf("tab adr : %p\n", &tab);
//     for (int i = 0; i < 10; i++) {
//         printf("tab[%d] adress : %p\n", i, &tab[i]);
//     }
// }

// q9
// int main () {
//     int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int *ptr_tab = tab;
//     while (ptr_tab <= &tab[9]) {
//         printf("%d", *ptr_tab);
//         (ptr_tab)++;
//     }
//     printf("\n-- impaires from the end now : ----\n");
//     while (ptr_tab >= &tab[0]) {
//         if (*ptr_tab % 2 != 0) {
//             printf("%d", *ptr_tab);
//         }
//         ptr_tab--;
//     }
// }

// q10
// #include <stdio.h>

// int main() {
//     double tab[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10};
//     double *dptr = tab;
//     void *vptr = tab;

//     printf("Using double*:\n");
//     for (int i = 0; i < 10; i++)
//         printf("%.1f ", *(dptr + i));
//     printf("\n");

//     printf("Using void* (cast to double*):\n");
//     for (int i = 0; i < 10; i++)
//         printf("%.1f ", *((double*)vptr + i));
//     printf("\n");

//     return 0;
// }

//q11 
// int main () {
//     int tab[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     for (int i = 0; i <= 10; i++) {
//         printf("tab[%d] = %d\n", i, *(tab + i));
//     }
// } // ça affiche une valeur aléatoire à la fin, logique : non définie et out of scope. should segmentation fault though. 

//q12
// #include <stdio.h>

// int main() {
//     int publicData[10]  = {1,2,3,4,5,6,7,8,9,10};
//     int privateData[10] = {101,102,103,104,105,106,107,108,109,110};

//     int *ptr = publicData;
//     printf("Valeur hors limite : %d\n", ptr[14]);  // Accès hors limites
//     return 0;
// }
/*
Accéder hors des limites d’un tableau C (ex. 15ᵉ case de publicData) peut lire des données privées contiguës (privateData), montrant un risque de fuite d’information. À retenir : toujours vérifier les indices, 
comprendre que arr[i] = *(arr + i) et que les tableaux sont contigus en mémoire. Pour les tableaux multidimensionnels, utiliser int tab[N][M] ou simuler avec un 1D (tab[i*M + j]).
*/

// Q13
// int main () {
//     double matrice[10][2] = {
//         {1.1, 2.2},
//         {3.3, 4.4},
//         {5.5, 6.6},
//         {7.7, 8.8},
//         {9.9, 10.10},
//         {11.11, 12.12},
//         {13.13, 14.14},
//         {15.15, 16.16},
//         {17.17, 18.18},
//         {19.19, 20.20}
//     };

//     for (int y = 0 ; y < 10 ; y++) {
//         for (int x = 0 ; x < 2 ; x++) {
//             printf("matrice[%d][%d] = %f at adress %p (line adress : %p)\n", y, x, matrice[y][x], &matrice[y][x], &matrice[y]);
//         }
//     }
// }
/*
matrice[0][0] = 1.100000 at adress 0x7fff69300900 (line adress : 0x7fff69300900)
matrice[0][1] = 2.200000 at adress 0x7fff69300908 (line adress : 0x7fff69300900)
matrice[1][0] = 3.300000 at adress 0x7fff69300910 (line adress : 0x7fff69300910)
matrice[1][1] = 4.400000 at adress 0x7fff69300918 (line adress : 0x7fff69300910)
matrice[2][0] = 5.500000 at adress 0x7fff69300920 (line adress : 0x7fff69300920)
matrice[2][1] = 6.600000 at adress 0x7fff69300928 (line adress : 0x7fff69300920)
matrice[3][0] = 7.700000 at adress 0x7fff69300930 (line adress : 0x7fff69300930)
matrice[3][1] = 8.800000 at adress 0x7fff69300938 (line adress : 0x7fff69300930)
matrice[4][0] = 9.900000 at adress 0x7fff69300940 (line adress : 0x7fff69300940)
matrice[4][1] = 10.100000 at adress 0x7fff69300948 (line adress : 0x7fff69300940)
matrice[5][0] = 11.110000 at adress 0x7fff69300950 (line adress : 0x7fff69300950)
matrice[5][1] = 12.120000 at adress 0x7fff69300958 (line adress : 0x7fff69300950)
matrice[6][0] = 13.130000 at adress 0x7fff69300960 (line adress : 0x7fff69300960)
matrice[6][1] = 14.140000 at adress 0x7fff69300968 (line adress : 0x7fff69300960)
matrice[7][0] = 15.150000 at adress 0x7fff69300970 (line adress : 0x7fff69300970)
matrice[7][1] = 16.160000 at adress 0x7fff69300978 (line adress : 0x7fff69300970)
matrice[8][0] = 17.170000 at adress 0x7fff69300980 (line adress : 0x7fff69300980)
matrice[8][1] = 18.180000 at adress 0x7fff69300988 (line adress : 0x7fff69300980)
matrice[9][0] = 19.190000 at adress 0x7fff69300990 (line adress : 0x7fff69300990)
matrice[9][1] = 20.200000 at adress 0x7fff69300998 (line adress : 0x7fff69300990)
*/

// Q14
// int main () {
//     double vecteur[20];
//     printf("\nVector of 20 doubles addresses:\n");
//     for (int i = 0; i < 20; i++) {
//         printf("vecteur[%d] = %p\n", i, (void*)&vecteur[i]);
//     }
// }
/*
✅ Observations
8  bytes split, because 2x4 byte s

Matrix 10x2

Each row’s address (matrice[i]) points to the first element of that row.

Memory is contiguous in row-major order, so matrice[i][0] and matrice[i][1] are consecutive.

Each row is separated by 2 * sizeof(double) bytes.

Vector of 20 doubles

Each element is consecutive, separated by sizeof(double).

Comparison

A 10x2 matrix is stored exactly like a vector of 20 doubles in memory (row-major), except that you can also access rows as matrice[i].

Pointer arithmetic works naturally: matrice[i][j] is equivalent to *((double*)matrice + i*2 + j).
*/

// Q15
// void swap(int *a, int *b) {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }
// int main () {
//     int a = 10;
//     int b = 20;
//     swap(&a, &b);
// }
// // En effet, lorsqu’on fait appel à une fonction qui prend en paramètres des variables, le contenu des variables
// est copié dans des variables internes à la fonction. À la fin de la fonction, ces variables internes sont
// détruites. En pratique, à aucun moment les variables ne sont modifiées.

// EN GROS PASSAGE PAR VALEUR SI PAS PAR POINTEUR : LVALUE VS RVALUE 

// Q16
// #include <stdio.h>

// int x = 10, y = 20;  // global variables

// void swap() {
//     printf("Before swap inside function: x=%d, y=%d\n", x, y);
//     int temp = x;
//     x = y;
//     y = temp;
//     printf("After swap inside function: x=%d, y=%d\n", x, y);
// }

// int main() {
//     printf("Before swap in main: x=%d, y=%d\n", x, y);
//     swap();
//     printf("After swap in main: x=%d, y=%d\n", x, y);
//     return 0;
// }
// global -> program memory . 

// Q17 
// void swap(int *a, int *b) {
//     printf("Inside swap BEFORE: *a=%d at %p, *b=%d at %p\n", *a, (void*)a, *b, (void*)b);
//     int temp = *a;
//     *a = *b;
//     *b = temp;
//     printf("Inside swap AFTER:  *a=%d at %p, *b=%d at %p\n", *a, (void*)a, *b, (void*)b);
// }

// --------------------------- *(tab + 5)

// int main() {
//     int x = 10, y = 20;
//     printf("In main BEFORE: x=%d at %p, y=%d at %p\n", x, (void*)&x, y, (void*)&y);
//     swap(&x, &y);
//     printf("In main AFTER:  x=%d at %p, y=%d at %p\n", x, (void*)&x, y, (void*)&y);
//     return 0;
// }

// ------------------- en gros : pass by value vs globals vs pass by pointers ---- in the 3 exos 

// Q18 Q19 Q20
// #include <string.h>
// int main () {
//     char *str="<-_->"; // \0 auto added
//     // for (char *p=str; *p != '\0'; p++) {
//     for (int i = 0; i < strlen(str); i++) {
//         printf("%c.", str[i]);
//     }
// }

// Q21

// int TP_strncmp(const char *str1, const char *str2) {
//     int i = 0;
//     for (i; str1[i] != '\0' && str2[i] != '\0'; i++) {
//         if (str1[i] != str2[i])
//             return (str2[i] - str1[i]);
//     }
//     if (str1[i] != str2[i]) return -1;

//     return 0;
// }

//Q22
// #include <string.h>

// int atoi(const char *str) {
//     int res = 0;
//     int coef = 1;

//     for (int i = strlen(str) - 1; i >= 0; i--) {
//         if (str[i] >= '0' && str[i] <= '9') {
//             res += ((int)str[i] - 48) * coef;
//             coef *= 10;
//         } else {
//             return -1;
//         }
//     }
//     return res;
// }

// int main() {
//     // atoi("23");
//     printf("%d", atoi("234506"));
// }

//Q23
// #include <string.h>
// #include <math.h>

// int size_entier(int entier) {
//     int res = 0;

//     while (entier > 0) {
//         res++;
//         entier /= 10;
//     }
//     return res;
// }

// char *itoa(int entier) {
//     int num_int = size_entier(entier);
//     char res[num_int + 1];
//     res[0] = '\0';
//     int power = pow(10, num_int - 1);
//     while (power > 0) {
//         char tmp_entier = (char)((entier / power) + 48);
//         entier -= (int)(tmp_entier - 48)*power;
//         strncat(res, &tmp_entier, 1);
//         power /= 10;
//     }
//     return strdup(res);
// }


// int main() {
//     printf("%s", itoa(722));
// }


//Q24

// int main (int argc, char **argv) {
//     printf(" we got %d params\n", argc);
//     while (*argv != NULL) {
//         printf("%s\n", *argv);
//         argv++;
//     }
// }

// Q25
// VERSION SIMPLE 
// #include <stdbool.h>

// bool premier(int entier) {
//     if (entier < 2) return false;
//     for (int i = 2; i <= sqrt(entier); i++) {
//         if (entier % i == 0) return false;
//     }
//     return true;
// }
// int main (int argc, char **argv) {
//     int max = atoi(argv[1]);
//     for (int i = 0; i < max; i++) {
//         if (premier(i))
//             printf("%i est premier\n");
//     }
// }

/*
Why 0 and 1 are not prime

0:

Divisible by everything (0 % n = 0 for any n).

So it doesn’t fit the “only divisible by 1 and itself” rule.

1:

Divisible only by 1.

But the definition requires two distinct divisors: 1 and the number itself.

For 1, those two are the same → so it doesn’t count.*/

// VERSION CRIBLE ERAST

// Q26
// scanf classique we know scanf("%d %s", &var, &var);

//Q27 - 1 if succ reading 1THING, if else then problemmm
// #include <stdio.h>

// int main() {
//     int valeur;
//     int ret;

//     printf("Veuillez saisir un entier : ");
//     ret = scanf("%d", &valeur);

//     printf("Valeur de retour de scanf : %d\n", ret);

//     if (ret == 1) {
//         printf("Lecture réussie, valeur = %d\n", valeur);
//         return 0; // tout s'est bien passé
//     } else {
//         printf("Erreur de lecture !\n");
//         return 1; // il y a eu un problème
//     }
// }

//Q28
// #include <math.h>
// #include <errno.h>
// #include <string.h>
// int main () {
//     pow(2,3); //success
//     pow(-2,0.5); //numerical argument out of domain
//     printf("%s %d", strerror(errno), (int) errno);
// }

// //Q29
// #include <stdio.h>
// #include <assert.h>

// double div_double(double a, double b) {
//     // Vérifie que le diviseur n'est pas nul
//     assert(b != 0);
//     return a / b;
// }

// int main() {
//     printf("10 / 11 = %f\n", div_double(10.0, 11.0));
//     printf("13 / -12 = %f\n", div_double(13.0, -12.0));
    
//     // Ceci déclenchera l'assertion
//     printf("42 / 0 = %f\n", div_double(42.0, 0.0));

//     return 0;
// }

/*
assert(condition)

Vérifie que condition est vraie.

Si faux :

Affiche message avec condition, fichier, ligne

Appelle abort() → core dump

Utilité : détecter erreurs logiques pendant le développement.

-DNDEBUG

Option de compilation pour désactiver toutes les assertions.

Usage : gcc -DNDEBUG fichier.c -o programme

Contexte : production → supprime le surcoût des vérifications.

Points clés

Assertions = développement/test, non production.

Avec assertions activées : division par zéro → abort() + message.

Sans assertions (-DNDEBUG) : le programme continue, résultats peuvent être inf ou nan.

Positionner les assert au début de la fonction pour vérifier les préconditions.

/0 = err
*/