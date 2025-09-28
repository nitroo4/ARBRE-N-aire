#ifndef ARBRES_H_INCLUDED
#define ARBRES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ELEMENTNULL 0
#define ARBRENULL NULL
#define MALLOC(x) ((x*) malloc(sizeof(x)))

typedef int Element;

typedef struct noeud {
    Element elmt;
    struct noeud* racine;   // premier fils
    struct noeud* suivant;  // frère suivant
} Noeud;

typedef Noeud* PArbre;

/* Prototypes */
PArbre creerNoeud(Element e);
void ajouterFils(PArbre parent, PArbre fils);
void traiter(Element e);
void parcoursInfixe(PArbre a);

#endif // ARBRE_H_INCLUDED
