Structure de données

Classe Noeud :

    Représente un nœud dans l'arbre

    Contient :

        valeur : la donnée stockée dans le nœud

        enfants : liste des nœuds enfants

Fonctions principales

1. parcours_postfixe(noeud) :

    Implémente un parcours en profondeur postfixe (post-order)

    Ordre de visite : enfants d'abord, puis racine

    Retourne une liste des valeurs dans l'ordre postfixe

2. afficher_arbre(noeud, niveau) :

    Affiche visuellement la structure de l'arbre

    Utilise l'indentation pour montrer les niveaux hiérarchiques

Arbre créé dans l'exemple
text

A
  └── B
    └── D
  └── C
    └── E
    └── F

Structure :

    Racine : A

    A a deux enfants : B et C

    B a un enfant : D

    C a deux enfants : E et F

Résultat du parcours postfixe

D → B → E → F → C → A

Explication de l'ordre :

    D (feuille, pas d'enfants)

    B (après son enfant D)

    E (feuille)

    F (feuille)

    C (après ses enfants E et F)

    A (après tous ses enfants)

