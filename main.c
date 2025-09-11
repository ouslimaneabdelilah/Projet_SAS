#include <stdio.h>
#include <string.h>
#define Max 200
int id = 1; // id unique
typedef struct
{
    int idAvion;
    char modele[30];
    int capacite;
    char statut[20];
} Avions;

typedef struct
{
    char nom[20];
    int nbAvions;
    Avions avion[Max];
} Aeroport;

Aeroport ae;

// function validation number
int Validation_choix(char prompt[])
{
    int number;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &number) == 1)
            break;
        while (getchar() != '\n')
            ;
        printf("S'il vous plait saisir un nombre n'est pas chain character \n");
    }
    return number;
}

void Ajoute_avions()
{
    int numb;
    printf("Combien le nombre de avion qui ajoute : ");
    scanf("%d", &numb);
    for (int i = 0; i < numb; i++)
    {
        ae.avion[ae.nbAvions].idAvion = id;
        printf("Saisir le model de l'avion %d : ", i + 1);
        scanf(" %[^\n]%*c", ae.avion[ae.nbAvions].modele);
        printf("Saisir la capacite de l'avion %d : ", i + 1);
        scanf("%d", &ae.avion[ae.nbAvions].capacite);
        strcpy(ae.avion[ae.nbAvions].statut, "Disponible");
        ae.nbAvions++;
        id++;
    }
}

void affichage_aeroport()
{
    printf("\n===============================================================\n");
    printf("Nom de l'aeroport : %s\n", ae.nom);
    printf("Nombre d'avions   : %d\n", ae.nbAvions);
    printf("===============================================================\n");
}

void affichage_avions()
{

    for (int i = 0; i < ae.nbAvions; i++)
    {
        printf("# id: %d |model : %s | capacite : %d | status : %s #\n", ae.avion[i].idAvion, ae.avion[i].modele, ae.avion[i].capacite, ae.avion[i].statut);
    }
}
int recherch_id()
{
    int id_r;
    printf("Saisir id de avion qui modifier : ");
    scanf("%d", &id_r);
    for (int i = 0; i < ae.nbAvions; i++)
    {
        if (id_r == ae.avion[i].idAvion)
            return i;
    }
    return -1;
}
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
            printf("#  0 # Retour au menu principal                               #\n");
            printf("===============================================================\n\n");

            choix = Validation_choix("Entrez votre choix : ");

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
                printf("Nouvelle capacite (actuelle: %d) : ", ae.avion[r].capacite);
                scanf("%d", &ae.avion[r].capacite);
                break;
            }
            case 3:
            {
                int st;
                printf("\n--- Choisir le nouveau statut ---\n");
                printf("1 - Disponible\n");
                printf("2 - En vol    \n");
                printf("3 - Maintenance\n");
                st = Validation_choix("Votre choix : ");
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

                printf("Nouvelle capacite (actuelle: %d) : ", ae.avion[r].capacite);
                scanf("%d", &ae.avion[r].capacite);

                int st;
                printf("\n--- Choisir le nouveau statut ---\n");
                printf("1 - Disponible\n");
                printf("2 - En vol\n");
                printf("3 - Maintenance\n");
                st = Validation_choix("Votre choix : ");
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
void trie_par_capacite(){
    for (int i = 0; i < ae.nbAvions; i++)
    {
        for (int j = i+1; j < ae.nbAvions; j++)
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
void trie_par_model(){
    for (int i = 0; i < ae.nbAvions; i++)
    {
        for (int j = i+1; j < ae.nbAvions; j++)
        {
            if (stricmp(ae.avion[i].modele,ae.avion[j].modele)>0)
            {
                Avions temp = ae.avion[i];
                ae.avion[i] = ae.avion[j];
                ae.avion[j] = temp;
            }
            
        }
        
    }
    
}
void trie_global(){
    printf("\n--- Choisir le nouveau statut ---\n");
    printf("1 - Trie par capacite\n");
    printf("2 - Trie par modele\n");
    int ch;
    ch = Validation_choix("Entre le choix de recherch : ");
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
    
    default:
        break;
    }

}
void Rechercher_un_avion()
{
    int ch;
    int index_r;
    printf("\n--- Choisir le choix de rechercher ---\n");
    printf("1 - recherch par id\n");
    printf("2 - recherch par model    \n");
    printf("Retour au menu principal  \n");
    ch = Validation_choix("Votre choix : ");
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
                ae.avion[i] = ae.avion[i + 1];
            }
            ae.nbAvions--;
            printf("Avion supprime \n");
            return;
        }
    }
    printf("Aucun avion trouve avec cet ID \n");
}
void Statistiques(){
    
}

int main()
{
    int choix;
    ae.nbAvions = 0;

    printf("Entrer le nom de l'aeroport : ");
    scanf(" %[^\n]%*c", ae.nom);
    do
    {

        printf("\n===============================================================\n");
        printf("                      MENU PRINCIPAL                           \n");
        printf("===============================================================\n");
        printf("#  1 # Afficher les informations de l'aeroport                #\n");
        printf("#  2 # Ajouter un avion                                       #\n");
        printf("#  3 # Modifier un avion                                      #\n");
        printf("#  4 # Supprimer un avion.                                    #\n");
        printf("#  5 # Afficher la liste des avions                           #\n");
        printf("#  6 # Rechercher un avion (par id ou par modele).            #\n");
        printf("#  7 # Trier les avions (par capacite, par modele)            #\n");
        printf("#  0 # Quitter                                                #\n");
        printf("===============================================================\n\n");
        choix = Validation_choix("Entre un choix dans Menu : ");
        switch (choix)
        {
        case 1:
            affichage_aeroport();
            break;
        case 2:
            Ajoute_avions();
            break;
        case 3:
            modifier_avion();
            break;
        case 4:
            supprimer();
            break;
        case 5:
            affichage_avions();
            break;
        case 6:
            Rechercher_un_avion();
            break;
        case 7:
            trie_global();
            break;
        case 0:
            printf("Fin du programme. \n");
            break;
        default:
            printf("Choix invalide \n");
            break;
        };
    } while (choix != 0);
}