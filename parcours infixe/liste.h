#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include "arbres.h"

typedef struct lst {
    PArbre val;
    struct lst* suiv;
} Liste;

typedef Liste* Pliste;

typedef struct {
    Pliste tete;
    Pliste queue;
} SFile;

/* Prototypes */
Pliste creerEltListe(PArbre x, Pliste suiv);
void creerFile(SFile* f);
bool fileVide(SFile f);
void enfiler(SFile* f, PArbre x);
PArbre defiler(SFile* f);

#endif // FILE_H_INCLUDED

