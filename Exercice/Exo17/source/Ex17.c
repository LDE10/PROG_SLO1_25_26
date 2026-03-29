// Canevas  Ex17   C. HUBER 

#include <stdio.h>



// Definition de S_Frame
typedef struct 
{
	char TypeInfo;
	int P1X;
	int P1Y;
	int P2X;
	int P2Y;
}S_Frame1;

typedef struct
{
	char TypeInfo;
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
	int Vue;
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
	int test;

	for (char i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			test = pt->Valeur.DefSeg1.TypeInfo;
			printf("%c", test);
		}
	}
}

// Fonction ShowFrame



// Programme principal
int main (void)
{
	char UserAnswer;
	// Variables pour test A
	int test;

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

				fonct.Valeur.DefSeg1.TypeInfo = "R";
				fonct.Valeur.DefSeg1.P1X = 20;
				fonct.Valeur.DefSeg1.P1Y = 25;
				fonct.Valeur.DefSeg1.P2X = 150;
				fonct.Valeur.DefSeg1.P2Y = 170;

				fonct.Valeur.DefSeg2.TypeInfo = "P";
				fonct.Valeur.DefSeg2.CentreX = 20;
				fonct.Valeur.DefSeg2.CentreY = 25;
				fonct.Valeur.DefSeg2.Longueur = 120;
				fonct.Valeur.DefSeg2.angle = 44.5;

				// Appel des fonctions pour affichage
				test = ShowSeg(&fonct);

				printf("%d = %d\n", test, test);

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