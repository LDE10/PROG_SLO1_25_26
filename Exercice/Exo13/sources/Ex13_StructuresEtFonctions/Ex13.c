// Solution Ex11 SL121_LOGA  C. HUBER 
// Sert de canevas pour l'Ex13
// Il faut transformer les fonctions et leur utilisation
// en utilisant des structures !!

#include <stdio.h>

struct S_ParamA
{
	int numerateur;
	int denominateur ;
};

struct S_ResA
{
	int rest;
	int resultat;
};

struct S_TestB
{
	int nombre;
	short int unites;
	short int dizaines;
	short int centaines;
};

// Fonction fDivInt
struct S_ResA fDivInt(struct S_ParamA *pt)
{
	struct S_ResA res;

	 res.rest = pt->numerateur % pt->denominateur;
	 res.resultat = pt->numerateur / pt->denominateur;
	 return res;
}  // fDivInt

// Fonction Extract
short int Extract(struct S_TestB *pt)
{ 
	short int Units;
	short int nombre = 0;

	Units = pt->nombre % 10;
	pt->centaines = (pt->nombre / 100);
	nombre = pt->nombre % 100;
	pt->dizaines = nombre / 10;
	return (Units);
}  // Extract


int main (void)
{
	char UserAnswer;
	// Variables pour test A
	int ValA_dividende, ValA_diviseur;
	int ResDiv, ResteDiv;

	// Variables pour test B
	int ValB;
	short int ResCent, ResDiz, ResUnit;

	printf("Ex13 Luc Derre \n");

	do {
		printf("Test A ou B, Q pour Quitter \n");
		scanf_s("%c%*c", &UserAnswer, 2);
		
		switch (UserAnswer) {
			case 'A':
			case 'a':
				printf("TestA: entrez le dividende  \n");
				scanf_s("%d%*c", &ValA_dividende);
				printf("TestA: entrez le diviseur  \n");
				scanf_s("%d%*c", &ValA_diviseur);

				struct S_ParamA parametre;
				parametre.numerateur = ValA_dividende;
				parametre.denominateur = ValA_diviseur;
				
				// test si diviseur est non nul
				if (ValA_diviseur != 0 ) 
				{
					struct S_ResA result = fDivInt(&parametre);

					//ResDiv = fDivInt(ValA_dividende, ValA_diviseur, &ResteDiv );

					printf ("Resultat de %d / %d =  %d, reste = %d \n", parametre.numerateur, parametre.denominateur, result.resultat, result.rest );
				}
				else
				{
					printf ("TestA : erreur division par 0 ! \n");
				}
			break;

			case 'B':
			case 'b':
				printf("TestB: entrez un nombre de 0  a 999 \n");
				scanf_s("%d%*c", &ValB);

				struct S_TestB valeurs;
				valeurs.nombre = ValB;

				if (ValB > 999)
				{
					ValB = 999;
					printf ("ValB limitee a %d \n", ValB); 
				}
				ResUnit = Extract (&valeurs);
				printf("ValB = %d centaine = %d dizaine = %d unite = %d \n", valeurs.nombre, valeurs.centaines, valeurs.dizaines, ResUnit);
		break;

		} // end switch
	
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));

	return (0);
}