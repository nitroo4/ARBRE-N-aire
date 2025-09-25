#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arbres.h"

typedef struct lst {
PArbre value;
struct lst * suiv;
} Liste;

typedef Liste* Pliste;
typedef struct sfiles {
Pliste tete;
Pliste queue;
} sFile;

Pliste creerEltListe(PArbre, Pliste);
void creerFile(sFile *);
bool fileVide(sFile);
void enfiler(sfile *, PArbre);
PArbre defiler(sFile *);

#endif // LISTE_H_INCLUDED
