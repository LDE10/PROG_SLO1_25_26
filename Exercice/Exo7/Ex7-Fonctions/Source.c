//--------------------------------------------------------------------------//
// Nom du projet		: Ex6
// Nom du fichier		: Démo.C
// Date de création		: 24.11.2025
// Date de modification : xx.xx.xxxx
//
// Auteur				: LDE
//
// Version				: 0.1
//
// Description			: Ex6
//
//
// Remarques :
//--------------------------------------------------------------------------//
//-- librairie standard --//
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "Header.h"

void main()
{
	char nbr = 0;
	char etoile_tot = 0;

	scanf_s("%hhd", &nbr);

	etoile_tot = AffTriangleAngleDH(nbr);

	printf("%d\n", etoile_tot);
}

char AffTriangleAngleDH(char nbr)
{
	char Nbr_tour_etoile = nbr;
	char Nbr_espace = nbr;
	char Nbr_etoile_tot = 0;

	for (int Nbr_tour = 0; Nbr_tour < Nbr_espace; Nbr_tour++)
	{
		for (int espace = 0; espace < Nbr_tour; espace++)
		{
			printf(" ");
		}

		for (int Nbr_etoile = 0; Nbr_etoile < Nbr_tour_etoile; Nbr_etoile++)
		{
			printf("*");
			Nbr_etoile_tot++;
		}
		printf("\n");

		if (Nbr_tour_etoile > 0)
		{
			Nbr_tour_etoile--;
		}
	}
	return(Nbr_etoile_tot);
}