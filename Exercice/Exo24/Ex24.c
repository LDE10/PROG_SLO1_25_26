// Canevas Exercice 24 fichiers aléatoire et allocation dynamique
// Auteur C. HUBER 20.06.2016
//
// Exercice réalisé par :   Prénom NOM


#include <stdlib.h>	// pour malloc
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// pour les fonctions fichiers


// Structure
// Définition de la structure pour le test C
typedef struct 
{
	double CoteA;
	double CoteB;
	double Surface;
} S_Ex24;


int main(void)
{
	FILE *fp1;	// Descripteur de fichier 
	char *FileName1 = "Ex24_Alire.bin"; 
	char UserAnswer;
	
	int i = 0;
		
	S_Ex24 Res;
	S_Ex24 *Tableau;		// pour allocation
	int ValIndice = 0;
	long NbOctets = 0;
	int NbStruct = 0;

	printf ("Exercice 24 Luc Derre \n");
	
	// 2ème phase ouverture pour lecture en binaire
	fp1 = fopen (FileName1, "rb");
	if (fp1 == NULL) 
	{
		printf ("Impossible d'ouvrir le fichier %s! \n", FileName1);
		scanf_s("%*c", &UserAnswer, 1);
	} 
	else 
	{
		printf("OK\n");

		// Détermine le nombre d'élément
		fseek(fp1, 0, SEEK_END);
		NbOctets = ftell(fp1);



		printf("Nombre de structure = %d\n", NbStruct);

		// Alloue le tableau
		

		// Copie le fichier dans le tableau
		

		do {
			printf("Test T ou Q pour Quitter \n");
			scanf_s("%c%*c", &UserAnswer, 2);
		
			switch (UserAnswer) {
				case 'T':
				case 't':
					printf("Entrez un rang de 0 a n -1  ! \n");
					scanf_s("%d%*c", &ValIndice);
					
					// Affiche le contenu de la  structure
					
				break;
			} // end switch
	
		} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));
	}

	fclose(fp1);
	return (0);
}
