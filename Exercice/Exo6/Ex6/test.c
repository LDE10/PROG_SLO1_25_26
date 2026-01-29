#include"Test.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>



char AffTriangleAngleDH(char nbr)
{
	char Nbr_tour_etoile = nbr;
	char Nbr_espace = nbr;
	char Nbr_etoile_tot = 0;	//Nombre total d'étoile 

		 for (int Nbr_tour = 0; Nbr_tour < Nbr_espace; Nbr_tour++)
		 {
			 for (int espace = 0; espace < Nbr_tour; espace++)	//Calcul du nombre d'espace
			 {
				 printf(" ");	//Affichage de l'espacement
			 }

			 for (int Nbr_etoile = 0; Nbr_etoile < Nbr_tour_etoile; Nbr_etoile++)	//Calcul du nombre d'étoile
			 {
				 printf("*");	//Affichage des étoiles
				 Nbr_etoile_tot++;
			 }
			 printf("\n");

			 if (Nbr_tour_etoile > 0)
			 {
				 Nbr_tour_etoile--;	//Diminution
			 }
		 }

	return(Nbr_etoile_tot);		//Valeur total d'étoile renvoyé
}