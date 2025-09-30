#ifndef FILE_H
#define FILE_H

#include "noeud.h"

typedef struct File {
    Noeud** noeuds;
    int debut;
    int fin;
    int taille;
} File;

File* creer_file(int taille);
void enfiler(File* f, Noeud* n);
Noeud* defiler(File* f);
int file_vide(File* f);
void liberer_file(File* f);

#endif