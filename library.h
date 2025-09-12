#ifndef LIBRARY_H
#define LIBRARY_H


#define Max 200
typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;
typedef struct
{
    int idAvion;
    char modele[30];
    int capacite;
    char statut[20];
    Date date_av;
} Avions;

typedef struct
{
    char nom[20];
    int nbAvions;
    Avions avion[Max];
} Aeroport;

extern Aeroport ae;
void remplirDonneesTest();
// function validation number
int Validation_int(char prompt[]);

// function date comparaison
int datecmp(int j1,int m1,int y1,int j2,int m2, int y2);

// function Ajoute l'avion
void Ajoute_avions();

// function affichage aeroport
void affichage_aeroport();

// function affichage avions
void affichage_avions();

// function recherch par id
int recherch_id();

// function rechercher par model
void recherch_model();

// function modifier un avion
void modifier_avion();

// function trie par capacite
void trie_par_capacite();

// function trie par model
void trie_par_model();

// function trie par date
void trie_par_date();

// function trie global appele les function trie capacite et modele
void trie_global();

// function de rechercher un avion appele function rechercher par id
void Rechercher_un_avion();

// function supprimier
void supprimer();

// function pour Statistique
void Statistiques();









#endif
