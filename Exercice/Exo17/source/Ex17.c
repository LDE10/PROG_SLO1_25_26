// Canevas  Ex17   C. HUBER 

#include <stdio.h>

// Definition de S_Frame
typedef struct 
{
	int P1X;
	int P1Y;
	int P2X;
	int P2Y;
}S_Frame1;

typedef struct
{
	int CentreX;
	int CentreY;
	int Longueur;
	double angle;
}S_Frame2;

// Definition de U_Frame
typedef union 
{
	S_Frame1 DefSeg1;
	S_Frame2 DefSeg2;
}U_Frame;

// Definition de S_DefSegment
typedef struct
{
	char TypeInfo;
	U_Frame Valeur;

}S_DefSegment;

// Fonction ShowSeg
ShowSeg(S_DefSegment* pt)
{
	int choix;

	if (pt->TypeInfo == 'R')
	{
		for (char i = 1; i < 6; i++)
		{
			switch (i)
			{
			case 1:
				choix = pt->TypeInfo;
				printf("TypeInfo = %c ", choix);
				break;

			case 2:
				choix = pt->Valeur.DefSeg1.P1X;
				printf("Pose1X = %d ", choix);
				break;

			case 3:
				choix = pt->Valeur.DefSeg1.P1Y;
				printf("Pose1Y = %d ", choix);
				break;

			case 4:
				choix = pt->Valeur.DefSeg1.P2X;
				printf("Pose2X = %d ", choix);
				break;

			case 5:
				choix = pt->Valeur.DefSeg1.P2Y;
				printf("Pose2Y = %d\n", choix);
				break;
			}
		}
	}
	else if (pt->TypeInfo == 'P')
	{
		for (char i = 1; i < 6; i++)
		{
			switch (i)
			{
			case 1:
				choix = pt->TypeInfo;
				printf("TypeInfo = %c ", choix);
				break;

			case 2:
				choix = pt->Valeur.DefSeg2.CentreX;
				printf("CentreX = %d ", choix);
				break;

			case 3:
				choix = pt->Valeur.DefSeg2.CentreY;
				printf("CentreY = %d ", choix);
				break;

			case 4:
				choix = pt->Valeur.DefSeg2.Longueur;
				printf("Longueur = %d ", choix);
				break;

			case 5:
				choix = pt->Valeur.DefSeg2.angle;
				printf("Angle = %f\n", choix);
				break;
			}
		}

	}
}


// Fonction ShowFrame



// Programme principal
int main (void)
{
	char UserAnswer;
	// Variables pour test A
	// 
	// Variables pour test B
	

	// A adapter !!!
	printf("Ex17  Luc Derre \n");

	do {
		printf("Test A ou B, Q pour Quitter \n");
		scanf_s("%c%*c", &UserAnswer, 2);
		
		switch (UserAnswer) {
			case 'A':
			case 'a':
				printf("TestA:  \n");
				// Initialisation champ par champ
				S_DefSegment fonct;

				fonct.TypeInfo = 'R';
				fonct.Valeur.DefSeg1.P1X = 20;
				fonct.Valeur.DefSeg1.P1Y = 25;
				fonct.Valeur.DefSeg1.P2X = 150;
				fonct.Valeur.DefSeg1.P2Y = 170;
				if (fonct.TypeInfo == 'R')
				{
					ShowSeg(&fonct);
				}

				fonct.TypeInfo = 'P';
				fonct.Valeur.DefSeg2.CentreX = 20;
				fonct.Valeur.DefSeg2.CentreY = 25;
				fonct.Valeur.DefSeg2.Longueur = 120;
				fonct.Valeur.DefSeg2.angle = 44.5;
				if (fonct.TypeInfo == 'P')
				{
					ShowSeg(&fonct);
				}

				// Appel des fonctions pour affichage

			break;

			case 'B':
			case 'b':
				printf("TestB:  \n");
				// Frame1 :  STX = 3 Code = 0x123,
				//           Datas = 0x12345678 et CRC = 0xACDC

				
				// Frame2 :  STX = 3 Code = 0x124,
				//           Datas = 0x10203040 et CRC = 0xABEF
				

				// Appel des fonctions pour affichage

				
			break;



		} // end switch
	
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));

	return (0);
}