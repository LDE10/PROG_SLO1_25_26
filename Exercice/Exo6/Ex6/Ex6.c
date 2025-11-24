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

	int ValB;
	short ValB1 = 0;
	double ValB2 = 0;

	do
	{
		printf("Test A ou B, Q pour Quitter\n");
		scanf_s(" %c", &Test, 1);

		if (Test == 'A')
		{
			printf("Test A : entrez un nombre entre 1 a 9\n");
			scanf_s("%d", &ValA);

			if (ValA > 9)
			{
				printf("TestA ValA limitee a 9 !\n");
				ValA = 9;
			}
			else if (ValA == 0)
			{
				printf("TestA : ValA forcee a 1\n");
				ValA = 1;
			}
			else if (ValA < 0)
			{
				printf("TestA: ValA est negatif !\n");
			}


			if ((ValA > 0 ) & (ValA < 10))
			{
				printf("%d ", ValA);

				for (char j = 0; j <= ValA; j++)
				{
					printf("*");
				}
				printf("\n");
			}
		}
		else if (Test == 'B')
		{
			printf("Test B : entrez une valeur entre 0 et 9\n");
			scanf_s("%d", &ValB);

			if ((ValB < 0) & (ValB > 9))
			{
				printf("TestB : ValB n'est pas entre 0 et 9 !\n");
			}

			if ((ValB >= 0) & (ValB <= 9))
			{
				for (char i = 0; i <= ValB; i++)
				{
					ValB1 = 100 + 10 * i;
					ValB2 = (float)ValB1 / (float) 10000;

					printf("TestB : i = %d ValB1 = %hu ValB2 = %lf\n", i, ValB1, ValB2);
				}
			}
		}
	} while (Test != 'Q');
}