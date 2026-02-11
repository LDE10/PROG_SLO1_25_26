// Canevas Ex14 SL124_LOGA SLO1 2ème semestre  C. HUBER 

#include <stdio.h>

// Structure S_hms
struct S_hms
{
	short int heurs;
	short int minutes;
	short int secondes;
};

// Structure S_hms_D

// Fonction CalSec
CalcSec(HeuresA, MinutesA)
{
	int SecH = 3600;
	int SecM = 60;
	int Secondes = 0;

	Secondes = (SecH * HeuresA) + (SecM * MinutesA);
	
	return Secondes;
}

// Fonction GetHMS_B
void GetHMS_B(int ValB,short *ptr )
{
	int SecH = 3600;
	int SecM = 60;
	int rest = 0;

	ptr[0] = ValB / SecH;

	rest = ValB % SecH;
	ptr[1] = rest / SecM;

	ptr[2] = rest % SecM;
}

// Fonction GetHMS_C
struct S_hms GetHMS_C(ValC)
{
	struct S_hms time;

	int SecH = 3600;
	int SecM = 60;
	int rest = 0;

	time.heurs = ValC / SecH;

	rest = ValC % SecH;
	time.minutes = rest / SecM;

	time.secondes = rest % SecM;

	return time;
}

// Fonction GetHMS_D


int main (void)
{
	char UserAnswer;
	// Variables pour test A
	int HeuresA, MinutesA, SecondesA;

	// Variables pour test B
	int ValB;
	short int time [3] = {0, 0, 0};

	// Variables pour test C
	int ValC;

	// Variables pour test D
	int ValD;


	printf("Ex14  Luc Derre \n");	// à MAJ

	do {
		printf("Test A, B, C ou D, Q pour Quitter \n");
		scanf_s("%c%*c", &UserAnswer, 2);
		
		switch (UserAnswer) {
			case 'A':
			case 'a':
				printf("TestA: entrez le nb d'heures  \n");
				scanf_s("%d%*c", &HeuresA);
				printf("TestA: entrez le nb de minutes  \n");
				scanf_s("%d%*c", &MinutesA);

				SecondesA = CalcSec(HeuresA, MinutesA);

				printf("TestA : Heures = %d Minuetes = %d Secondes = %d\n", HeuresA, MinutesA, SecondesA);

			break;

			case 'B':
			case 'b':
				printf("TestB: entrez un nombre de secondes \n");
				scanf_s("%d%*c", &ValB);

				GetHMS_B(ValB, time);

				printf("TestB : %d sec represente %d [h] %d [m] %d [s]\n", ValB, time[0], time[1], time[2]);

			break;

			case 'C':
			case 'c':
				printf("TestC: entrez un nombre de secondes \n");
				scanf_s("%d%*c", &ValC);

				struct S_hms temps = GetHMS_C(ValC);

				printf("TestC : %d sec represente %d [h] %d [m] %d [s]\n", ValC, temps.heurs, temps.minutes, temps.secondes);

			break;

			case 'D':
			case 'd':
				printf("TestD: entrez un nombre de secondes \n");
				scanf_s("%d%*c", &ValD);
				// Suite TestD

				printf("TestD : %d sec represente %d [h] %d [m] %d [s]\n", ValD, );

			break;
		} // end switch
	
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));

	return (0);
}