class Noeud:
    def __init__(self, valeur):
        self.valeur = valeur
        self.enfants = []

def parcours_postfixe(noeud):
    """Parcours postfixe sans aucune bibliothèque externe"""
    if noeud is None:
        return []
    
    resultat = []
    
    
    for enfant in noeud.enfants:
        resultat.extend(parcours_postfixe(enfant))
    
    resultat.append(noeud.valeur)
    return resultat

def afficher_arbre(noeud, niveau=0):
    """Affichage visuel sans bibliothèque externe"""
    if noeud is not None:
        print("  " * niveau + "└── " + str(noeud.valeur))
        for enfant in noeud.enfants:
            afficher_arbre(enfant, niveau + 1)

racine = Noeud("A")
b = Noeud("B") 
c = Noeud("C")
d = Noeud("D")
e = Noeud("E")
f = Noeud("F")

racine.enfants = [b, c]
b.enfants = [d]
c.enfants = [e, f]

print("Arbre créé :")
afficher_arbre(racine)

print("\nParcours postfixe :")
resultat = parcours_postfixe(racine)
print(" → ".join(resultat))
