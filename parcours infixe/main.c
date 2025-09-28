#include "arbres.h"

int main() {
    // cree les noeud
    PArbre racine = creerNoeud(15);

    PArbre n2 = creerNoeud(1);
    PArbre n3 = creerNoeud(45);
    PArbre n4 = creerNoeud(99);
    PArbre n5 = creerNoeud(4);
    PArbre n6 = creerNoeud(64);
    PArbre n7 = creerNoeud(6);
    PArbre n8 = creerNoeud(120);
    PArbre n9 = creerNoeud(9);
    PArbre n10 = creerNoeud(3);
    PArbre n11 = creerNoeud(11);

    // enfant de noeud
    ajouterFils(racine, n2);
    ajouterFils(racine, n3);
    ajouterFils(racine, n4);

    ajouterFils(n2, n5);
    ajouterFils(n2, n6);
    ajouterFils(n2, n7);
    ajouterFils(n2, n8);

    ajouterFils(n3, n9);
    ajouterFils(n3, n10);

    ajouterFils(n4, n11);

    printf("Parcours infixe de l'arbre n-aire:\n");
    parcoursInfixe(racine);
    printf("\n");

    return 0;
}
