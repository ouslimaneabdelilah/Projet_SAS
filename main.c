#include <stdio.h>
#include <string.h>
int id = 0;
typedef struct
{
    int idAvion;
    char modele[30];
    int capacite;
    char statut[];
} Avions;

typedef struct
{
    char nom[20];
    int nbAvions;
    Avions avion[200];
} Aeroport;
Aeroport ae;


//function validation number 
int Validation_choix(char prompt[])
{
    int number;
    while (1)
    {
        printf(prompt);
        if (scanf("%d", &number) == 1)break;
        while(getchar()!='\n');
        printf("\nS'il vous plait saisir un nombre n'est pas chain character ");
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
        printf("Saisir la model de l'avion %d : ", i + 1);
        scanf(" %[^\n]%*c", ae.avion[ae.nbAvions].modele);
        printf("Saisir la capacite de l'avion %d : ", i + 1);
        scanf("%d", &ae.avion[ae.nbAvions].capacite);
        strcpy(ae.avion[ae.nbAvions].statut,"Disponible");
        ae.nbAvions++;
        id++;
    }
}

void affichage_aeroport()
{

    printf("===============================================================\n");
    printf("#           Nome            |        Nombre des avions        #\n");
    printf("===============================================================\n");
    printf("#        %s                 |                 %d            #", ae.nom, ae.nbAvions);
}
void affichage_avions()
{

    for (int i = 0; i < ae.nbAvions; i++)
    {
        printf("# id: %d |model : %s | capacite : %d | status : %d #\n", ae.avion[i].idAvion, ae.avion[i].modele,ae.avion[i].capacite,ae.avion[i].statut);
    }
}
void supprimer(){
    int id_s;
    printf("Saisir l'id de avion qui supprimier : ");
    scanf("%d",&id_s);
    for (int i = 0; i < ae.nbAvions; i++)
    {
        if (id_s == ae.avion[i].idAvion)
        {
            for (int j = i; i < ae.nbAvions; i++)
            {
                ae.avion[i] = ae.avion[i+1];

            }
            ae.nbAvions--;
            
        }
        
    }
    
    
    
}





int main()
{
    int choix;
    ae.nbAvions = 0;

    printf("Entrer le nom de l aeroport");
    scanf(" %[^\n]%*c", &ae.nom);
    do
    {

        printf("\n===============================================================\n");
        printf("                      MENU PRINCIPAL                           \n");
        printf("===============================================================\n");
        printf("#  1 # Afficher les informations de l'aéroport et de sa flotte#\n");
        printf("#  2 # Ajouter un avion                                       #\n");
        printf("#  2 # Modifier un avion                                       #\n");
        printf("#  3 # Supprimer un avion.                                    #\n");
        printf("#  4 # Afficher la liste des avions                           #\n");
        printf("#  5 # Rechercher un avion (par id ou par modele).            #\n");
        printf("#  6 # Trier les avions (par capacite, par modele)            #\n");
        printf("#  0 # Quitter                                                #\n");
        printf("===============================================================\n\n");
        choix= Validation_choix("Entre un choix dans Menu : ");
        switch (choix)
        {
        case 1:
            affichage_aeroport();
            break;
        case 2:
            Ajoute_avions();
            break;
        case 3:
            affichage_avions();
            break;
        case 4:
            supprimer();
            break;

        default:
            break;
        };
    } while (choix != 0);
}