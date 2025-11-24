//--------------------------------------------------------------------------//
// Nom du projet		: Démo_25_26
// Nom du fichier		: Démo.C
// Date de création		: 29.09.2025
// Date de modification : 03.11.2025
//
// Auteur				: LDE
//
// Version				: 0.1
//
// Description			: Démo de programme
//
//
// Remarques :
//--------------------------------------------------------------------------//
//-- librairie standard --//
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//-- librairie perso --//
//#include ""					"" -> pour chercher une librairie dans son dossier

//-- définition--//


//-- constante globale --//


//--------------------------------------------------------------------------//
//-- Programme principal =>
//-- nom fonction : main
//-- paramètre entrée : -
//-- paramètre sortie : -
//-- paramètre IN-OUT : -
//-- description	  : programme principal =>
//--------------------------------------------------------------------------//
void main()
{
	//-- variable--//
	char Test;
	int ValA;

	char int8Val;
	unsigned char  uint8Val;

	do
	{
		printf("Test A ou B, Q pour Quitter\n");
		scanf_s(" %c", &Test, 1);

		if (Test == 'A')
		{
			printf("Test A : entrez un nombre de 1 a 9\n");
			scanf_s("%d", &ValA);

			if (ValA > 9)
			{
				printf("ValA limitee a 9\n");

				for (char i = 0; i < 9; i++)
				{
					printf("i = %d\n", i);
				}
			}
			else if (ValA > 0)
			{
				for (char i = 0; i < ValA; i++)
				{
					printf("i = %d\n", i);
				}
			}
		}
		else if (Test == 'B')
		{
			printf("Test B : affichage val signee et non signee\n");

			for (int8Val = 125, uint8Val = 125; int8Val < 135 && uint8Val < 135; int8Val++, uint8Val++)
			{
				printf("int8Val = %+3d uint8Val = %d\n", int8Val, uint8Val);
			}
		}
	} while (Test != 'Q');
}