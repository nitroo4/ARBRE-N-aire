#include "arbres.h"

PArbre creerNoeud(Element e) {
    PArbre n = MALLOC(Noeud);
    if (!n) {
        fprintf(stderr, "Erreur allocation mémoire\n");
        exit(1);
    }
    n->elmt = e;
    n->racine = NULL;
    n->suivant = NULL;
    return n;
}

void ajouterFils(PArbre racines, PArbre fils) {
    if (!racines || !fils) return;
    if (!racines->racine) {racines->racine = fils;
    } else {
        PArbre vers = racines->racine;
        while (vers->suivant) {
            vers = vers->suivant;
        }
        vers->suivant = fils;
    }
}
void traiter(Element e) {
    printf("%d ", e);
}

void parcoursInfixe(PArbre a) {
    if (!a) return;
    PArbre fils = a->racine;
    if (fils) {
        parcoursInfixe(fils);
        traiter(a->elmt);
        fils = fils->suivant;
        while (fils) {
            parcoursInfixe(fils);
            fils = fils->suivant;
        }
    } else {
        /*feuille*/traiter(a->elmt);
    }
}
