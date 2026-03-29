// Canevas  Ex17   C. HUBER 

#include <stdio.h>

// Definition de S_Frame
//A
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

//B
typedef union 
{
	struct
	{
	char STX : 3;
	short code : 13;
	int Datas;
	int CRC;
	};

}u_Frame1;



// Definition de U_Frame
//A
typedef union 
{
	S_Frame1 DefSeg1;
	S_Frame2 DefSeg2;
}U_Frame;

//B
//typedef union
//{
//	S_Frame trame;
//}U_Frame2;

// Definition de S_DefSegment
typedef struct
{
	char TypeInfo;
	U_Frame Valeur;

}S_DefSegment;

// Fonction ShowSeg
ShowSeg(S_DefSegment* pt)
{
	if (pt->TypeInfo == 'R')
	{

		printf("TypeInfo = %c ", pt->TypeInfo);
		printf("Pose1X = %d ", pt->Valeur.DefSeg1.P1X);
		printf("Pose1Y = %d ", pt->Valeur.DefSeg1.P1Y);
		printf("Pose2X = %d ", pt->Valeur.DefSeg1.P2X);
		printf("Pose2Y = %d\n", pt->Valeur.DefSeg1.P2Y);

	}
	else if (pt->TypeInfo == 'P')
	{
		printf("TypeInfo = %c ", pt->TypeInfo);
		printf("CentreX = %d ", pt->Valeur.DefSeg2.CentreX);
		printf("CentreY = %d ", pt->Valeur.DefSeg2.CentreY);
		printf("Longueur = %d ", pt->Valeur.DefSeg2.Longueur);
		printf("Angle = %f\n", pt->Valeur.DefSeg2.angle);
	}
}


// Fonction ShowFrame
ShowFrame(u_Frame1* pt)
{

	if (pt->Datas == 12345678)
	{
		printf("STX = %d Code = %d Datas = %d Crc = %x\n", pt->STX, pt->code, pt->Datas, pt->CRC);

		//for (char i = 0; i < sizeof(pt->trame); i++)
		//{
		//	printf("%x ", pt->test);
		//}
		//printf("\n");
	}
	else
	{
		printf("STX = %d Code = %d Datas = %d Crc = %x\n", pt->STX, pt->code, pt->Datas, pt->CRC);
	}

}


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

				u_Frame1 trame;
				char* pt = &trame;

				printf("Taille S_Frame2 = %d\n", sizeof(trame));


				trame.STX = 3;
				trame.code = 123;
				trame.Datas = 12345678;
				trame.CRC = 0xACDC;

				ShowFrame(&trame);

				for (char i = 0; i < sizeof(trame); i++)
				{
					printf("%02x ", pt[i]);
				}
				printf("\n");

				trame.STX = 3;
				trame.code = 124;
				trame.Datas = 10203040;
				trame.CRC = 0xABEF;

				ShowFrame(&trame);

				for (char i = 0; i < sizeof(trame); i++)
				{
					printf("%02x ", pt[i]);
				}
				printf("\n");



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