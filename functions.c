#include "library.h"
#include <string.h>
#include <stdio.h>

Aeroport ae;

void remplirDonneesTest() {
    ae.nbAvions = 10;

    Avions avionsTest[10] = {
        {1, "Boeing 737", 160, "Disponible", {1, 1, 2023}},
        {2, "Airbus A320", 180, "Maintenance", {5, 2, 2023}},
        {3, "Boeing 777", 280, "Disponible", {10, 3, 2023}},
        {4, "Airbus A380", 200, "En vol", {15, 4, 2023}},
        {5, "Embraer E190", 100, "Disponible", {20, 5, 2023}},
        {6, "Cessna 172", 4, "Disponible", {25, 6, 2023}},
        {7, "Boeing 747", 216, "Maintenance", {30, 7, 2023}},
        {8, "Airbus A350", 150, "Disponible", {2, 8, 2023}},
        {9, "Concorde", 92, "En vol", {10, 9, 2023}},
        {10, "Bombardier CRJ200", 50, "Disponible", {12, 10, 2023}}
    };

    for (int i = 0; i < 10; i++) {
        ae.avion[i] = avionsTest[i];
    }

    // strcpy(ae.nom, "Casablanca");
}

// function validation number
int Validation_int(char prompt[])
{
    int number;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &number) == 1)
            if (number >= 0 && number < 300)
            {
                break;
            }

        while (getchar() != '\n')
            ;
        printf("S'il vous plait saisir un nombre n'est pas chaine de caracteres \n");
    }
    return number;
}
// function date comparaison
int datecmp(int j1,int m1,int y1,int j2,int m2, int y2){
    if (y1>y2)
    {
        return 1;

    }else if(y1<y2){
        return -1;
    }else{
        if(m1>m2){
            return 1;
        }else if (m1<m2)
        {
            return -1;
        }else{
            if (j1>j2)
            {
                return 1;
            }else if (j1<j2)
            {
                return -1;

            }
            else{
                return 0;
            }

        }

    }
    return 0;

}
// function Ajoute l'avion
void Ajoute_avions()
{
    int numb;
    printf("Combien le nombre de avion qui ajoute : ");
    scanf("%d", &numb);
    for (int i = 0; i < numb; i++)
    {
        ae.avion[ae.nbAvions].idAvion = ae.nbAvions + 1;
        printf("Saisir le model de l'avion %d : ", i + 1);

        scanf(" %[^\n]%*c", ae.avion[ae.nbAvions].modele);
        ae.avion[ae.nbAvions].capacite = Validation_int("Saisir la capacite de l'avion  : ");
        while (1)
        {
            printf("Saisir la date en Form (Jour/mois/annee) : ");
            if (scanf("%d / %d / %d", &ae.avion[ae.nbAvions].date_av.jour, &ae.avion[ae.nbAvions].date_av.mois, &ae.avion[ae.nbAvions].date_av.annee) == 3)
            {
                if ((ae.avion[ae.nbAvions].date_av.jour <= 31 && ae.avion[ae.nbAvions].date_av.jour > 0) && (ae.avion[ae.nbAvions].date_av.mois <= 12 && ae.avion[ae.nbAvions].date_av.mois > 0) && (ae.avion[ae.nbAvions].date_av.annee > 1903))
                {
                    break;
                }
            };
            while (getchar() != '\n');
            printf("S'il vous plait saisir date valide le type de date integer est sont format (Jour/mois/année) \n");
        }
        strcpy(ae.avion[ae.nbAvions].statut, "Disponible");
        ae.nbAvions++;
        printf("===============================================================\n");
    }
    printf("Ajoute Succuss!!!!!\n");
}
// function affichage aeroport
void affichage_aeroport()
{
    printf("\n===============================================================\n");
    printf("# Nom de l'aeroport : %s                                  #\n", ae.nom);
    printf("# Nombre d'avions   : %d                                        #\n", ae.nbAvions);
    printf("===============================================================\n");
}
// function affichage avions
void affichage_avions()
{

    for (int i = 0; i < ae.nbAvions; i++)
    {
        printf("# id: %d |modele : %s | capacite : %d | status : %s | date entre : | %d / %d / %d#\n",
               ae.avion[i].idAvion, ae.avion[i].modele, ae.avion[i].capacite, ae.avion[i].statut,
               ae.avion[i].date_av.jour, ae.avion[i].date_av.mois, ae.avion[i].date_av.annee);
    }
}
// function recherch par id
int recherch_id()
{
    int id_r;
    printf("Saisir l'id de l'avion a modifier: ");
    scanf("%d", &id_r);
    for (int i = 0; i < ae.nbAvions; i++)
    {
        if (id_r == ae.avion[i].idAvion)
            return i;
    }
    return -1;
}
// function rechercher par model
void recherch_model()
{
    char modele[30];
    printf("Saisir le modele de l'avion : ");
    scanf(" %[^\n]%*c", modele);

    int trouve = 0;
    for (int i = 0; i < ae.nbAvions; i++)
    {
        if (stricmp(ae.avion[i].modele, modele) == 0)
        {
            printf("\n=== Avion trouve ===\n");
            printf("# id: %d | modele : %s | capacite : %d | statut : %s #\n",
                   ae.avion[i].idAvion,
                   ae.avion[i].modele,
                   ae.avion[i].capacite,
                   ae.avion[i].statut);
            trouve = 1;
        }
    }
    if (!trouve)
    {
        printf("Aucun avion trouve avec ce modele \n");
    }
}

// function modifier un avion
void modifier_avion()
{
    int r = recherch_id();
    if (r >= 0)
    {
        int choix;
        do
        {
            printf("\n===============================================================\n");
            printf("                      MENU de Modification                       \n");
            printf("===============================================================\n");
            printf("#  1 # Modifier le modele                                     #\n");
            printf("#  2 # Modifier la capacite                                   #\n");
            printf("#  3 # Modifier le statut                                     #\n");
            printf("#  4 # Modifier toutes les infos de l'avion                   #\n");
            printf("#  5 # Modifier la date                                       #\n");
            printf("#  0 # Retour au menu principal                               #\n");
            printf("===============================================================\n\n");

            choix = Validation_int("Entrez votre choix : ");

            switch (choix)
            {
            case 1:
            {
                char nouveauModele[30];
                printf("Nouveau modele (actuel: %s) : ", ae.avion[r].modele);
                scanf(" %[^\n]%*c", nouveauModele);
                strcpy(ae.avion[r].modele, nouveauModele);
                break;
            }
            case 2:
            {
                // printf("Nouvelle capacite (actuelle: %d) : ", ae.avion[r].capacite);
                // scanf("%d", &ae.avion[r].capacite);
                ae.avion[r].capacite = Validation_int("Nouvelle capacite : ");
                break;
            }
            case 3:
            {
                int st;
                printf("\n--- Choisir le nouveau statut ---\n");
                printf("1 - Disponible\n");
                printf("2 - En vol    \n");
                printf("3 - Maintenance\n");
                st = Validation_int("Votre choix : ");
                switch (st)
                {
                case 1:
                    strcpy(ae.avion[r].statut, "Disponible");
                    break;
                case 2:
                    strcpy(ae.avion[r].statut, "En vol");
                    break;
                case 3:
                    strcpy(ae.avion[r].statut, "Maintenance");
                    break;
                default:
                    printf("Statut invalide \n");
                    break;
                }
                break;
            }
            case 4:
            {
                char nouveauModele[30];
                printf("Nouveau modele (actuel: %s) : ", ae.avion[r].modele);
                scanf(" %[^\n]%*c", nouveauModele);
                strcpy(ae.avion[r].modele, nouveauModele);

                printf("Nouveau capacite (actuel: %d) : ", ae.avion[r].capacite);
                scanf("%d", &ae.avion[r].capacite);

                int st;
                printf("\n--- Choisir le nouveau statut ---\n");
                printf("1 - Disponible\n");
                printf("2 - En vol\n");
                printf("3 - Maintenance\n");
                printf("0 - Retour au menu principal\n");
                st = Validation_int("Votre choix : ");
                switch (st)
                {
                case 1:
                    strcpy(ae.avion[r].statut, "Disponible");
                    break;
                case 2:
                    strcpy(ae.avion[r].statut, "En vol");
                    break;
                case 3:
                    strcpy(ae.avion[r].statut, "Maintenance");
                    break;
                default:
                    printf("Statut invalide \n");
                    break;
                }
                break;
            }
            case 5:
                while (1)
                {
                    printf("Saisir nauvelle date en Form (Jour/mois/annee) (actuelle: %d / %d / %d): ",ae.avion[r].date_av.jour, ae.avion[r].date_av.mois, ae.avion[r].date_av.annee);
                    if (scanf("%d / %d / %d", &ae.avion[r].date_av.jour, &ae.avion[r].date_av.mois, &ae.avion[r].date_av.annee) == 3)
                    {
                        if ((ae.avion[r].date_av.jour <= 31 && ae.avion[r].date_av.jour > 0) && (ae.avion[r].date_av.mois <= 12 && ae.avion[r].date_av.mois > 0) && (ae.avion[r].date_av.annee > 1903))
                        {
                            break;
                        }
                    };
                    while (getchar() != '\n')
                        break;
                    printf("S'il vous plait saisir date valide le type de date integer est sont format (Jour/mois/année) \n");
                }
                break;
            case 0:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide \n");
                break;
            }
        } while (choix != 0);
    }
    else
    {
        printf("Avion introuvable \n");
    }
}

// function trie par capacite
void trie_par_capacite()
{
    for (int i = 0; i < ae.nbAvions; i++)
    {
        for (int j = i + 1; j < ae.nbAvions; j++)
        {
            if (ae.avion[i].capacite > ae.avion[j].capacite)
            {
                Avions temp = ae.avion[i];
                ae.avion[i] = ae.avion[j];
                ae.avion[j] = temp;
            }
        }
    }
}
// function trie par model
void trie_par_model()
{
    for (int i = 0; i < ae.nbAvions; i++)
    {
        for (int j = i + 1; j < ae.nbAvions; j++)
        {
            if (stricmp(ae.avion[i].modele, ae.avion[j].modele) > 0)
            {
                Avions temp = ae.avion[i];
                ae.avion[i] = ae.avion[j];
                ae.avion[j] = temp;
            }
        }
    }
}
// function trie par date
void trie_par_date(){
    for (int i = 0; i < ae.nbAvions; i++)
    {
        for (int j = i+1; j < ae.nbAvions; j++)
        {
            if (datecmp(ae.avion[i].date_av.jour,ae.avion[i].date_av.mois,ae.avion[i].date_av.annee,ae.avion[j].date_av.jour,ae.avion[j].date_av.mois,ae.avion[j].date_av.annee)==1)
            {
                Avions temp = ae.avion[i];
                ae.avion[i] = ae.avion[j];
                ae.avion[j] = temp;
            }
            
        }
        
    }
    
}
// function trie global appele les function trie capacite et modele
void trie_global()
{
    printf("\n--- Choisir le nouveau statut ---\n");
    printf("1 - Trie par capacite\n");
    printf("2 - Trie par modele\n");
    printf("3 - Trie par date\n");
    int ch;
    ch = Validation_int("Entre le choix de recherch : ");
    switch (ch)
    {
    case 1:
        trie_par_capacite();
        affichage_avions();
        break;
    case 2:
        trie_par_model();
        affichage_avions();
        break;
    case 3:
        trie_par_date();
        affichage_avions();
        break;

    default:
        break;
    }
}

// function de rechercher un avion appele function rechercher par id
void Rechercher_un_avion()
{
    int ch;
    int index_r;
    printf("\n--- Choisir le choix de rechercher ---\n");
    printf("1 - recherch par id\n");
    printf("2 - recherch par model    \n");
    printf("Retour au menu principal  \n");
    ch = Validation_int("Votre choix : ");
    switch (ch)
    {
    case 1:
        index_r = recherch_id();
        if (index_r >= 0)
        {
            printf("\n=== Avion trouve ===\n");
            printf("# id: %d | modele : %s | capacite : %d | statut : %s #\n",
                   ae.avion[index_r].idAvion,
                   ae.avion[index_r].modele,
                   ae.avion[index_r].capacite,
                   ae.avion[index_r].statut);
        }
        else
        {
            printf("Avion introuvable \n");
        }
        break;
    case 2:
        recherch_model();
        break;
    default:
        printf("Statut invalide \n");
        break;
    }
}
// function supprimier
void supprimer()
{
    int id_s;
    printf("Saisir l'id de l'avion a supprimier : ");
    scanf("%d", &id_s);
    for (int i = 0; i < ae.nbAvions; i++)
    {
        if (id_s == ae.avion[i].idAvion)
        {
            for (int j = i; j < ae.nbAvions - 1; j++)
            {
                ae.avion[j] = ae.avion[j + 1];
            }
            ae.nbAvions--;
            printf("Avion supprime \n");
        }
    }
    printf("Aucun avion trouve avec cet ID \n");
}

// function pour Statistique
void Statistiques()
{
    int m = 0, d = 0, e = 0, av_d = 0;
    int total_capacite = 0;
    printf("\n===============================================================\n");
    printf("                         Statistiques                            \n");
    printf("===============================================================\n");
    for (int i = 0; i < ae.nbAvions; i++)
    {
        if (stricmp(ae.avion[i].statut, "Disponible") == 0)
        {
            av_d++;
        }
    }

    printf("Nombre total d avions dans le parc : %d avions\n", av_d);

    for (int i = 0; i < ae.nbAvions; i++)
    {
        if (stricmp(ae.avion[i].statut, "Disponible") == 0)
        {
            d++;
        }
        else if (stricmp(ae.avion[i].statut, "En vol") == 0)
        {
            e++;
        }
        else
        {
            m++;
        }
    }

    printf("Nombre d avions par statut : \n");
    printf("# Disponible  : %d \n", d);
    printf("# En vol :  %d \n", e);
    printf("# Maintenance %d : \n", m);

    for (int i = 0; i < ae.nbAvions; i++)
    {
        total_capacite += ae.avion[i].capacite;
    }
    printf("# Capacité totale de la flotte  : %d\n", total_capacite);

    // min et max
    trie_par_capacite();
    printf("# L avion Grande Capacite : \n");
    printf("# Id : %d | #Modele : %s | #Capacite : %d | #statut : %s \n", ae.avion[ae.nbAvions - 1].idAvion, ae.avion[ae.nbAvions - 1].modele, ae.avion[ae.nbAvions - 1].capacite, ae.avion[ae.nbAvions - 1].statut);
    
    printf("# L avion Petite Capacite : \n");
    printf("# Id : %d | #Modele : %s | #Capacite : %d | #statut : %s \n", ae.avion[0].idAvion, ae.avion[0].modele, ae.avion[0].capacite, ae.avion[0].statut);

    float average = (av_d * 100) / ae.nbAvions;
    float coffiece = average / 100;
    printf("# pourcentage d avions disponibles dans l aeroport : %.0f %% \n", average);
    printf("# coefficient sous forme numerique : %.0f  ", coffiece);
}