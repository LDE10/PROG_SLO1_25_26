// Canevas Ex10  C. HUBER 

#include <stdio.h>
#include <math.h>	// pour ceil et floor


// Fonction FtestA
double FtestA(const double ValA, double* decimal); 

// Fonction Extract
unsigned short int Extract(const unsigned long ValB, unsigned short int* H, unsigned short int* M);


int main (void)
{
	char UserAnswer;

	// Variables pour test A
	double ValA;
	double Vald = 0;
	double rest = 0;
	
	// Variables pour test B
	unsigned long ValB;
	unsigned short int Heur = 0;
	unsigned short int Minute = 0;
	unsigned short int Seconde = 0;
	

	printf("Ex10 Luc Derre \n");
	do {
		printf("Test A ou B, Q pour Quitter \n");
		scanf_s("%c%*c", &UserAnswer, 2);
		
		switch (UserAnswer) 
		{
			case 'A':
			case 'a':
				printf("TestA: entrez un nombre float  \n");
				scanf_s("%lf%*c", &ValA);

				Vald = FtestA(ValA, &rest);
				
				printf("ValA = %f PartInt = %f PartFract = %f\n", ValA, Vald, rest);
			break;

			case 'B':
			case 'b':
				printf("TestB: entrez un nombre de secondes \n");
				scanf_s("%d%*c", &ValB);

				Seconde = Extract( ValB,&Heur, &Minute);

				printf("ValB = %d NbHeurs = %d NbMinutes = %d NbSecondes = %d\n", ValB, Heur, Minute, Seconde);
				break;

		} // end switch
	
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));

	return (0);
}

double FtestA(const double ValA, double* decimal)
{
	double Vald = 0;
	

	Vald = (int)ValA;
	*decimal = ValA - Vald;
	Vald = Vald;

}

unsigned short int Extract(const unsigned long ValB, unsigned short int* H, unsigned short int* M)
{
	char heur = 0;
	char minutes = 0;
	char NbrSeconde = 0;	//Nombre de secondes
	char Sm = 60;			//60 seconde dans 1 minute
	int Sh = 3600;			//3600 seconde dans 1 heur
	int Minutes = 0;		//Nombre de seconde total


	*H = ValB / Sh;					//Calcul du nombre d'heur
	heur = *H;

	Minutes = ValB - (Sh * heur);		//Calcul du nombre de minutes et seconde
	*M = Minutes / Sm;				//Calcul du nombre de minutes
	minutes = *M,

	NbrSeconde = Minutes - (Sm * minutes);
}
