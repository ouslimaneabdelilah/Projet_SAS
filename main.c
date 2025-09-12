#include "library.h"
#include <string.h>
#include <stdio.h>

int main()
{
    int choix;

    printf("Entrer le nom de l'aeroport : ");
    scanf(" %[^\n]%*c", ae.nom);
    remplirDonneesTest();
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
        printf("#  7 # Trier les avions (par capacite, par modele,par date)   #\n");
        printf("#  8 # Afficher Statistiques                                  #\n");
        printf("#  0 # Quitter                                                #\n");
        printf("===============================================================\n\n");
        choix = Validation_int("Entre un choix dans Menu : ");
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
        case 8:
            Statistiques();
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