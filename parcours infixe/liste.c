#include "liste.h"

Pliste creerEltListe(PArbre x, Pliste suiv) {
    Pliste ptr = MALLOC(Liste);
    if (!ptr) {
        fprintf(stderr, "ERREUR ALLOCATION MEMOIRE FILE\n");
        exit(1);
    }
    ptr->val = x;
    ptr->suiv = suiv;
    return ptr;
}

void creerFile(SFile* f) {
    f->tete = NULL;
    f->queue = NULL;
}

bool fileVide(SFile f) {
    return (f.tete == NULL);
}

void enfiler(SFile* f, PArbre x) {
    Pliste ptr = creerEltListe(x, NULL);
    if (f->queue) f->queue->suiv = ptr;
    else f->tete = ptr;
    f->queue = ptr;
}

PArbre defiler(SFile* f) {
    if (!f->tete) return ARBRENULL;
    Pliste ptr = f->tete;
    PArbre x = ptr->val;
    f->tete = ptr->suiv;
    if (f->queue == ptr) f->queue = NULL;
    free(ptr);
    return x;
}
