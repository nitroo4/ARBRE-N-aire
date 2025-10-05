#ifndef NOEUD_H
#define NOEUD_H

#define MAX_ENFANTS 10

typedef struct Noeud {
    int valeur;
    int nb_enfants;
    struct Noeud** enfants;
} Noeud;

Noeud* creer_noeud(int val);
void ajouter_enfant(Noeud* parent, Noeud* enfant);
void liberer_arbre(Noeud* racine);

#endif