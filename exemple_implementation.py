class Noeud:
    def __init__(self, valeur, parent=None):
        self.valeur = valeur
        self.parent = parent
        self.premierEnfant = None
        self.frereSuivant = None

def creer_noeud(valeur, parent=None):
    """Fonction équivalente à creerNoeudParent"""
    return Noeud(valeur, parent)

def ajouter_enfant(parent, enfant):
    """Fonction équivalente à ajouterEnfantParent"""
    if parent.premierEnfant is None:
        parent.premierEnfant = enfant
    else:
        dernier = parent.premierEnfant
        while dernier.frereSuivant is not None:
            dernier = dernier.frereSuivant
        dernier.frereSuivant = enfant
    enfant.parent = parent

def construire_arbre_exemple():
    """Construction de l'arbre exemple avec chaînage"""
    # Structure de l'arbre :
    #       1
    #     / | \
    #    2  3  4
    #   / \    |
    #  5   6   7
    
    racine = creer_noeud(1)
    
    n2 = creer_noeud(2, racine)
    n3 = creer_noeud(3, racine)
    n4 = creer_noeud(4, racine)
    n5 = creer_noeud(5, n2)
    n6 = creer_noeud(6, n2)
    n7 = creer_noeud(7, n4)
    
    # Construction des chaînages
    ajouter_enfant(racine, n2)
    ajouter_enfant(racine, n3)
    ajouter_enfant(racine, n4)
    
    ajouter_enfant(n2, n5)
    ajouter_enfant(n2, n6)
    
    ajouter_enfant(n4, n7)
    
    return racine

def parcours_avec_chainage(racine):
    """Parcours utilisant le chaînage (version adaptée)"""
    print("=== Parcours utilisant le chaînage ===")
    
    courant = racine
    niveau = 0
    
    while courant is not None:
        # Afficher le nœud courant
        print("  " * niveau + str(courant.valeur))
        
        # Si le nœud a des enfants, descendre
        if courant.premierEnfant is not None:
            courant = courant.premierEnfant
            niveau += 1
        elif courant.frereSuivant is not None:
            # Sinon, passer au frère suivant
            courant = courant.frereSuivant
        else:
            # Remonter jusqu'à trouver un frère
            while courant is not None and courant.frereSuivant is None:
                courant = courant.parent
                niveau -= 1
            if courant is not None:
                courant = courant.frereSuivant

def navigation_complete(racine):
    """Navigation complète avec chaînage"""
    print("=== Navigation complète avec chaînage ===")
    
    courant = racine
    
    while courant is not None:
        print(f"Nœud: {courant.valeur}")
        
        # Afficher le parent
        print("  Parent: ", end="")
        if courant.parent:
            print(courant.parent.valeur)
        else:
            print("NULL")
        
        # Afficher les enfants
        print("  Enfants: ", end="")
        enfant = courant.premierEnfant
        while enfant is not None:
            print(enfant.valeur, end=" ")
            enfant = enfant.frereSuivant
        print()
        
        # Afficher le frère suivant
        print("  Frère suivant: ", end="")
        if courant.frereSuivant:
            print(courant.frereSuivant.valeur)
        else:
            print("NULL")
        
        print()
        
        # Passer au prochain nœud (parcours en largeur)
        if courant.premierEnfant is not None:
            # Stocker la position pour revenir
            temp = courant
            courant = courant.premierEnfant
            
            # Trouver le dernier enfant pour chaînage horizontal
            dernier_enfant = courant
            while dernier_enfant.frereSuivant is not None:
                dernier_enfant = dernier_enfant.frereSuivant
            
            # Relier le dernier enfant au frère suivant du parent
            if temp.frereSuivant is not None:
                dernier_enfant.frereSuivant = temp.frereSuivant
        else:
            courant = courant.frereSuivant

def afficher_chainages(racine, niveau=0):
    """Fonction utilitaire pour afficher les chaînages"""
    if racine is None:
        return
    
    # Indentation selon le niveau
    print("  " * niveau + str(racine.valeur), end="")
    
    # Afficher les liens
    print(" (P:", end="")
    if racine.parent:
        print(racine.parent.valeur, end="")
    else:
        print("N", end="")
    
    print(", E:", end="")
    enfant = racine.premierEnfant
    while enfant is not None:
        print(enfant.valeur, end="")
        enfant = enfant.frereSuivant
        if enfant:
            print(",", end="")
    
    print(", F:", end="")
    if racine.frereSuivant:
        print(racine.frereSuivant.valeur, end="")
    else:
        print("N", end="")
    print(")")
    
    # Appels récursifs
    afficher_chainages(racine.premierEnfant, niveau + 1)
    afficher_chainages(racine.frereSuivant, niveau)

def liberer_arbre_chainage(racine):
    """Libération mémoire avec chaînage"""
    if racine is None:
        return
    
    # Libérer récursivement les enfants
    liberer_arbre_chainage(racine.premierEnfant)
    
    # Libérer les frères
    liberer_arbre_chainage(racine.frereSuivant)
    
    # En Python, la libération est automatique grâce au garbage collector
    # Cette fonction est surtout pour montrer l'équivalent

# Fonction principale de démonstration
def main():
    print("=== CRÉATION DE CHAÎNAGE DANS UN ARBRE N-AIRE ===\n")
    
    # Construction d'un arbre avec chaînage fratrie
    racine = construire_arbre_exemple()
    
    print("Structure arborescente avec chaînages:")
    afficher_chainages(racine)
    print()
    
    navigation_complete(racine)
    
    # Parcours avec chaînage
    parcours_avec_chainage(racine)
    
    # En Python, pas besoin de libération manuelle explicite
    # grâce au garbage collector

if __name__ == "__main__":
    main()