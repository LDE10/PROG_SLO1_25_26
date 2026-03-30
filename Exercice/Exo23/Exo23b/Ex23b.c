// canevas Exercice 23b SL124_LOGA
// utilitaires fichiers 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// pour les fonctions fichiers

#include "ShowUtil.h"

int main(void)
{
	char *FileNameA = "Ex23b_A.bin"; 
	char *FileNameB = "Ex23b_B.bin"; 
	char *FileNameC = "Ex23b_C.bin"; 

	char UserAnswer;
	int status;
		

	// A adapter
	printf ("Exercice 23b Prenom NOM \n");
	
	do {
		printf("Test A , B ou C, Q pour Quitter \n");
		scanf_s("%c%*c", &UserAnswer, 2);
		
		switch (UserAnswer) {
			case 'A':
			case 'a':
				printf("TestA: fonction ShowHex  \n");
				status = ShowHex(FileNameA);
				if (status == 0) printf("TestA: pas OK ! \n");
			break;

			case 'B':
			case 'b':
				printf("TestB: fonction ShowInt16  \n");
				status = ShowInt16(FileNameB);
				if (status == 0) printf("TestB: pas OK ! \n");
			break;

			case 'C':
			case 'c':
				printf("TestC: fonction ShowFloat  \n");
				status = ShowFloat(FileNameC);
				if (status == 0) printf("TestC: pas OK ! \n");
			break;


		} // end switch
	
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));

	
	return (0);
}
