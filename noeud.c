#include "noeud.h"
#include <stdlib.h>

Noeud* creer_noeud(int val) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (!nouveau) return NULL;
    
    nouveau->valeur = val;
    nouveau->nb_enfants = 0;
    nouveau->enfants = (Noeud**)malloc(MAX_ENFANTS * sizeof(Noeud*));
    
    return nouveau;
}

void ajouter_enfant(Noeud* parent, Noeud* enfant) {
    if (parent->nb_enfants < MAX_ENFANTS) {
        parent->enfants[parent->nb_enfants++] = enfant;
    }
}

void liberer_arbre(Noeud* racine) {
    if (!racine) return;
    
    for (int i = 0; i < racine->nb_enfants; i++) {
        liberer_arbre(racine->enfants[i]);
    }
    
    free(racine->enfants);
    free(racine);
}