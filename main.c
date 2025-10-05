#include <stdio.h>
#include "noeud.h"
#include "parcours.h"

int main() {
    // Création de l'arbre
    Noeud* racine = creer_noeud(1);
    Noeud* n2 = creer_noeud(2);
    Noeud* n3 = creer_noeud(3);
    Noeud* n4 = creer_noeud(4);
    Noeud* n5 = creer_noeud(5);
    
    // Construction de l'arbre
    ajouter_enfant(racine, n2);
    ajouter_enfant(racine, n3);
    ajouter_enfant(n2, n4);
    ajouter_enfant(n2, n5);
    
    // Parcours
    parcours_largeur(racine);  // Affiche: 1 2 3 4 5
    
    // Nettoyage
    liberer_arbre(racine);
    return 0;
}