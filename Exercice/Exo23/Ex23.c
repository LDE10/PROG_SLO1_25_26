// Canevas SL124_LOGA Ex23.c
// Auteur C. HUBER 6.06.2016
//
// Exercice réalisé par : 
  

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>		// pour sqrt


// Définition de la structure pour le test C
typedef struct {
	int Valeur;
	double RacineValeur;
} S_TestC;




// FtestB
// Cette fonction recoit un pointeur sur un fichier qui contient un texte
// Il faut compter le nombre de fois que l'on trouve la lettres à rechercher
// Ce nombre est à retourner (type unsigned short)



// FtestC
// Cette fonction recoit un pointeur sur la structure S_TestC
// Affichage sur une ligne 


int main (void)
{
	char  UserAnswer;
	short sortie;
		
	// Variables pour TestA
	char *FileNameA = "Ex23ResA.txt";
	
	

	// Variables pour TestB
	char *FileNameB = "Ex23DonB.txt";
	
	

	// Variables pour TestC
	char *FileNameC = "Ex23DonC.bin";
	
	

	// Affichage : "Exercice 23 Prenom NOM"

	
	sortie = 0; // faux, reste dans la boucle
	do {
		printf("Test A, B ou C, Q pour Quitter \n");
		scanf_s("%c%*c", &UserAnswer, 2);
		
		switch (UserAnswer) {
			
			case 'A':
			case 'a':
				// Test A
				printf("TestA: Generation du fichier %s \n", FileNameA);
				

				
                printf("TestA: Le fichier %s est en principe OK !\n", FileNameA);
			break;

			case 'B':
			case 'b':
				// Test B
				printf("TestB: entrez la lettre a rechercher dans le fichier %s ! \n", FileNameB);
				// Saisie
				
			break;

			case 'C':
			case 'c':
				// Test C
				printf("TestC: Traitement du contenu du fichier %s ! \n", FileNameC);
				// Ouverture du fichier
				
			break;


			case 'Q':
			case 'q':
				sortie = 1;
			break;
		}
	
	} while (sortie == 0);

	return (0);
}