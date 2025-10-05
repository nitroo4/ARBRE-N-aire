#include "parcours.h"
#include "file.h"
#include <stdio.h>

void parcours_largeur(Noeud* racine) {
    if (!racine) return;
    
    File* file = creer_file(100);
    enfiler(file, racine);
    
    printf("Parcours en largeur: ");
    
    while (!file_vide(file)) {
        Noeud* courant = defiler(file);
        
        // TRAITEMENT 
        printf("%d ", courant->valeur);
        
        for (int i = 0; i < courant->nb_enfants; i++) {
            if (courant->enfants[i]) {
                enfiler(file, courant->enfants[i]);
            }
        }
    }
    printf("\n");
    
    liberer_file(file);
}