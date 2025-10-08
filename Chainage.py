class NoeudComplet:
    def __init__(self, valeur):
        self.valeur = valeur
        self.parent = None
        self.premierEnfant = None
        self.dernierEnfant = None
        self.frerePrecedent = None
        self.frereSuivant = None

def creer_noeud_complet(valeur):
    """Fonction équivalente à creerNoeudComplet"""
    return NoeudComplet(valeur)

def ajouter_enfant_complet(parent, enfant):
    """Fonction équivalente à ajouterEnfantComplet"""
    if parent is None or enfant is None:
        return
    
    # Lier l'enfant à son parent
    enfant.parent = parent
    
    if parent.premierEnfant is None:
        # Premier enfant
        parent.premierEnfant = enfant
        parent.dernierEnfant = enfant
    else:
        # Chaînage avec le dernier enfant
        enfant.frerePrecedent = parent.dernierEnfant
        parent.dernierEnfant.frereSuivant = enfant
        parent.dernierEnfant = enfant

# Exemple d'utilisation
if __name__ == "__main__":
    # Création des nœuds
    racine = creer_noeud_complet(1)
    enfant1 = creer_noeud_complet(2)
    enfant2 = creer_noeud_complet(3)
    enfant3 = creer_noeud_complet(4)
    
    # Construction de l'arbre
    ajouter_enfant_complet(racine, enfant1)
    ajouter_enfant_complet(racine, enfant2)
    ajouter_enfant_complet(racine, enfant3)
    
    # Vérification des liens
    print(f"Racine: {racine.valeur}")
    print(f"Premier enfant: {racine.premierEnfant.valeur}")
    print(f"Dernier enfant: {racine.dernierEnfant.valeur}")
    print(f"Enfant1 -> frère suivant: {enfant1.frereSuivant.valeur}")
    print(f"Enfant2 -> frère précédent: {enfant2.frerePrecedent.valeur}")
    print(f"Enfant2 -> frère suivant: {enfant2.frereSuivant.valeur}")