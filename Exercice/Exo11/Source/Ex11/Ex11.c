// Canevas Ex11 SLO1 SL121_LOGA 

#include <stdio.h>


// Fonction fDivInt
int fDivInt(const int ValA_dividende,const int ValA_diviseur, int *rest);

// Fonction Extract
int Extract(const int ValB, int* d, int* u);

int main (void)
{
	char UserAnswer;
	// Variables pour test A
	int ValA_dividende, ValA_diviseur;
	int result = 0, rest = 0;
	// Variables pour test B
	int ValB;
	int c = 0, d = 0, u = 0;	//Variable centaine, dizaine et unité

	// Invite exercice 11
	printf("EX11 Luc Derre  \n");
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

				if (ValA_dividende == 0)
				{
					printf("TestA: errreur division par 0 !  \n");
				}
				else
				{
					result =  fDivInt( ValA_dividende,  ValA_diviseur, &rest);
					printf("Resultat de %d / %d = %d rest = %d\n", ValA_dividende, ValA_diviseur, result, rest);
				}
		break;

			case 'B':
			case 'b':
				printf("TestB: entrez un nombre de 0 a 999 \n");
				scanf_s("%d%*c", &ValB);

				if (ValB > 999)
				{
					ValB = 999;
					printf("ValB limiter a 999 !\n");
					
				}

					c = Extract(ValB, &d, &u);

				
				printf("ValB = %d centaine %d dizaine = %d unite = %d \n", ValB, c, d, u);

		break;

		} // end switch
	
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));

	return (0);
}

int fDivInt(const int ValA_dividende,const int ValA_diviseur, int* rest)
{
	float result = 0;
	int restes = 0;
	int reste = 0;
	int resultat = 0;

	result = (float)ValA_dividende / (float)ValA_diviseur;
	*rest = ValA_dividende % ValA_diviseur;
	resultat = result;

}

int Extract(const int ValB, int* d, int* u)
{
	int c = 0;
	int dizaine = 0;
	const dix = 10;
	const centaine = 100;

	*u = ValB % dix;
	dizaine = ValB / dix;
	*d = dizaine % dix;
	c = ValB / centaine;
}
