#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cellule {
   int valeur;
   struct Cellule * suivant;
} Cellule;

typedef struct Pile {
   Cellule * tete;
} Pile;

void empiler(Pile * pile, int val) {
   /* votre code ici */
}

int depiler(Pile * pile, int * res) {
   Cellule * suivant;
   if (pile->tete==NULL) {
      return 0;
   }
   *res = pile->tete->valeur;
   suivant = pile->tete->suivant;
   free(pile->tete);
   pile->tete = suivant;
   return 1;
}

int vide(Pile * pile) {
   return pile->tete==NULL;
}

Pile* init(void) {
   Pile *  pile;
   pile = (Pile*) malloc(sizeof(Pile));
   pile->tete = NULL;
   return pile;
}

void destroy(Pile * pile) {
   Cellule * todestroy;
   while(pile->tete) {
      todestroy = pile->tete;
      pile->tete = pile->tete->suivant;
      free(todestroy);
   }
   free(pile);
}

int main(void) 
{
   char lecture[100];

   Pile *  pile;
   pile = init();
   int val;

   fscanf(stdin,"%99s",lecture);
   while (strcmp(lecture,"bye")!=0)
   {
      if (strcmp(lecture,"push")==0)
      {
         fscanf(stdin,"%99s",lecture);
         val = strtol(lecture,NULL,10);
         empiler(pile,val);
      }
      else if (strcmp(lecture,"pop")==0)
      {
         if (depiler(pile,&val))
            printf("%d\r\n",val);
      }
      else if (strcmp(lecture,"vide")==0)
      {
            printf("%s\r\n",vide(pile)?"O":"N");
      }
      fscanf(stdin,"%99s",lecture);
   }
   destroy(pile);
   return 0;
}
