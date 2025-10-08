# 🌳 Documentation détaillée : Arbre N-aire avec chaînage en Python

Ce fichier explique en détail chaque constructeur, fonction et partie du code Python permettant de créer, parcourir et afficher un **arbre n-aire** à l’aide de **chaînages entre les nœuds**.

---

## 🧩 Classe `Noeud`

```python
class Noeud:
    def __init__(self, valeur, parent=None):
        self.valeur = valeur
        self.parent = parent
        self.premierEnfant = None
        self.frereSuivant = None

Ce fichier explique en détail chaque constructeur, fonction et partie du code Python permettant de créer, parcourir et afficher un **arbre n-aire** à l’aide de **chaînages entre les nœuds**.



## 🧩 Classe `Noeud`

python
class Noeud:
    def __init__(self, valeur, parent=None):
        self.valeur = valeur
        self.parent = parent
        self.premierEnfant = None
        self.frereSuivant = None
🧱 Attributs

valeur : contient la donnée ou valeur du nœud (par exemple un nombre ou un identifiant).

parent : référence vers le nœud parent. Si le nœud est la racine, cette valeur est None.

premierEnfant : référence vers le premier enfant de ce nœud.

frereSuivant : référence vers le prochain frère du nœud (autrement dit, le nœud suivant au même niveau hiérarchique).

🎯 Rôle

Cette structure permet de représenter un arbre sans utiliser de listes :
chaque nœud connaît son premier enfant et son frère suivant → ce qu’on appelle un chaînage fraternelle.

🌱 Fonction creer_noeud

def creer_noeud(valeur, parent=None):
    """Fonction équivalente à creerNoeudParent"""
    return Noeud(valeur, parent)


🧱 Paramètres

valeur : la valeur à stocker dans le nœud.

parent (optionnel) : le nœud parent.

🎯 Rôle

Simplifie la création d’un nœud sans devoir appeler directement la classe Noeud.


Fonction ajouter_enfant

Crée un nouveau nœud avec une valeur donnée, et éventuellement un parent.

🧱 Paramètres

valeur : la valeur à stocker dans le nœud.

parent (optionnel) : le nœud parent.

🎯 Rôle

Simplifie la création d’un nœud sans devoir appeler directement la classe Noeud

Fonction ajouter_enfant

def ajouter_enfant(parent, enfant):
    if parent.premierEnfant is None:
        parent.premierEnfant = enfant
    else:
        dernier = parent.premierEnfant
        while dernier.frereSuivant is not None:
            dernier = dernier.frereSuivant
        dernier.frereSuivant = enfant
    enfant.parent = parent

Ajoute un nœud enfant à un nœud parent.

⚙️ Fonctionnement

Si le parent n’a pas encore d’enfant, on assigne directement cet enfant comme premierEnfant.

Sinon, on parcourt la chaîne des frères jusqu’au dernier (frereSuivant) et on ajoute le nouvel enfant à la fin.

Fonction construire_arbre_exemple
def construire_arbre_exemple():
    ...

On met à jour le lien parent de l’enfant.

Construit un arbre n-aire d’exemple suivant la structure :


      1
    / | \
   2  3  4
  / \    |
 5   6   7


⚙️ Étapes

Création des nœuds 1 à 7 avec creer_noeud.

Liaison des enfants avec ajouter_enfant.

Retourne la racine (nœud 1).


Fonction parcours_avec_chainage
def parcours_avec_chainage(racine):
    
Effectue un parcours complet de l’arbre en utilisant uniquement les chaînages (premierEnfant et frereSuivant).

⚙️ Détails

On part de la racine et on descend vers le premier enfant si possible.

Si un nœud n’a pas d’enfant, on passe à son frère suivant.

Si aucun frère n’existe, on remonte au parent jusqu’à trouver un frère disponible.

🎯 Objectif

Parcourir tout l’arbre sans utiliser de liste ou de pile externe.

Fonction navigation_complete
def navigation_complete(racine):
    ...

🔍 Description

Permet d’afficher les liens complets d’un nœud :

Son parent

Ses enfants

Son frère suivant

⚙️ Fonctionnement

Pour chaque nœud, on affiche :

Sa valeur

Son parent (parent.valeur ou NULL)

Ses enfants (via premierEnfant et frereSuivant)

Son frère suivant

Le parcours relie temporairement certains nœuds pour simuler un parcours en largeur.

Fonction afficher_chainages
def afficher_chainages(racine, niveau=0):

Affiche visuellement les chaînages d’un arbre.

🧱 Informations affichées

Pour chaque nœud :

Sa valeur

Son parent (P)

Ses enfants (E)

Son frère suivant (F)

⚙️ Exemple de sortie
1 (P:N, E:2,3,4, F:N)
  2 (P:1, E:5,6, F:3)
  3 (P:1, E:N, F:4)
  4 (P:1, E:7, F:N)

 Fonction liberer_arbre_chainage

 Description

Libère récursivement la mémoire d’un arbre.

⚙️ Détails

Appelle récursivement la fonction sur les enfants (premierEnfant) et les frères (frereSuivant).

En Python, la libération est automatique (grâce au garbage collector), donc cette fonction est symbolique.

Fonction principale main
def main():
    print("=== CRÉATION DE CHAÎNAGE DANS UN ARBRE N-AIRE ===\n")
    racine = construire_arbre_exemple()
    afficher_chainages(racine)
    navigation_complete(racine)
    parcours_avec_chainage(racine)

Description

Point d’entrée du programme.

⚙️ Étapes principales

Construction de l’arbre d’exemple.

Affichage des chaînages.

Navigation complète (parents/enfants/frères).

Parcours général de l’arbre.

