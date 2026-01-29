//  SL121_LOGA canevas Ex12  L.Derré

#include <stdio.h>


// Fonction ShowItems
double ShowItems(double i, double *pt);


int main (void)
{
	char UserAnswer;
	// Variables pour test A
	double TableA [10];
	double *pt;
	pt = &TableA[0];

	double item = 0;

	// Variables pour test B
	

	printf("Ex12  Luc Derre \n");  

	// Boucle initialisation du tableau du testA


	do {
		printf("Test A ou B, Q pour Quitter \n");
		scanf_s("%c%*c", &UserAnswer, 2);
		
		switch (UserAnswer) {
			case 'A':
			case 'a':
				printf("TestA: affichage des informations de TableA \n");
				
				for (char i = 0; i <= 9; i++)
				{
					item = ShowItems(i, &pt);
					printf("TestA : indice = %d, adresse item = %x, valeur item = %0.2f\n", i, pt, item);
					pt++;
				}
			break;

			case 'B':
			case 'b':
				printf("TestB: entrez le numero de ligne (max 15) \n");
				// suite test B 

			break;

		} // end switch
	
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));

	return (0);
}

double ShowItems(double i, double* pt)
{
	const double dix = 10.00;
	const double cent = 100.00;

	double item = 0;


	item = (i / cent) + dix;
}