#include "file.h"
#include <stdlib.h>

File* creer_file(int taille) {
    File* f = (File*)malloc(sizeof(File));
    f->noeuds = (Noeud**)malloc(taille * sizeof(Noeud*));
    f->debut = 0;
    f->fin = 0;
    f->taille = taille;
    return f;
}

void enfiler(File* f, Noeud* n) {
    if (f->fin < f->taille) {
        f->noeuds[f->fin++] = n;
    }
}

Noeud* defiler(File* f) {
    if (f->debut >= f->fin) return NULL;
    return f->noeuds[f->debut++];
}

int file_vide(File* f) {
    return f->debut >= f->fin;
}

void liberer_file(File* f) {
    free(f->noeuds);
    free(f);
}