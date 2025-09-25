#ifndef ARBRES_H_INCLUDED
#define ARBRES_H_INCLUDED
#define MALLOC(X) ((x * ) malloc(sizeof(x))
#define ELEMENTNULL 0
#define ARBRENULL NULL
#include "liste.h"
typedef int Element;

typedef struct arb {
    Element elmt;
    Element child;
    struct arb** child ;
    int equilibre;
    int hauteur;
} Arbre;

typedef Arbre* PArbre;

typedef struct {
    int elmt;
    int info;
} TArbre;

int max(int, int);
int min(int, int);

bool estVide(PArbre);
bool estFeuille(PArbre);
Element racine(PArbre);
PArbre modifierRacine(PArbre, Element);



#endif // ARBRES_H_INCLUDED
