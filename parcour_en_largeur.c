#define MAX_ENFANTS 10

typedef struct Noeud {
    int valeur;
    int nb_enfants;
    struct Noeud** enfants;
} Noeud;

typedef struct File {
    Noeud** noeuds;
    int debut;
    int fin;
    int taille;
} File;

Noeud* creer_noeud(int val) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (!nouveau) return 0;
    
    nouveau->valeur = val;
    nouveau->nb_enfants = 0;
    nouveau->enfants = (Noeud**)malloc(MAX_ENFANTS * sizeof(Noeud*));
    
    return nouveau;
}

File* creer_file(int taille) {
    File* f = (File*)malloc(sizeof(File));
    f->noeuds = (Noeud**)malloc(taille * sizeof(Noeud*));
    f->debut = 0;
    f->fin = 0;
    f->taille = taille;
    return f;
}

void enfiler(File* f, Noeud* n) {
    if (f->fin < f->taille) {
        f->noeuds[f->fin] = n;
        f->fin = f->fin + 1;
    }
}

Noeud* defiler(File* f) {
    if (f->debut >= f->fin) return 0;
    Noeud* temp = f->noeuds[f->debut];
    f->debut = f->debut + 1;
    return temp;
}

int file_vide(File* f) {
    return f->debut >= f->fin;
}

void parcours_largeur(Noeud* racine) {
    if (!racine) return;
    
    File* file = creer_file(100);
    enfiler(file, racine);
    
    while (!file_vide(file)) {
        Noeud* courant = defiler(file);
        
        // Traitement du noeud
    
        
        for (int i = 0; i < courant->nb_enfants; i++) {
            if (courant->enfants[i]) {
                enfiler(file, courant->enfants[i]);
            }
        }
    }
    
    free(file->noeuds);
    free(file);
}