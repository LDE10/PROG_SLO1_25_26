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
unsigned short FtestB(FILE *fp1, char search)
{
	int lettre = 0;
	char lettreSearch = search;
	char count = 0;
	
	do 
	{
		lettre = getc(fp1);

		if (lettreSearch == lettre)
		{
			count++;
		}
	} while (lettre != EOF);

	return count;
}



// FtestC
// Cette fonction recoit un pointeur sur la structure S_TestC
// Affichage sur une ligne 


int main (void)
{
	char  UserAnswer;
	short sortie;
		
	// Variables pour TestA
	FILE* fp1;
	char *FileNameA = "Ex23ResA.txt";
	float tab[26] =
	{
		0,1, 1.414, 1.732, 2, 2.236, 2.449, 2.646, 2.828, 3, 3.162, 3.317, 3.464, 3.606, 3.742, 3.873, 4, 4.123, 4.243, 4.359, 4.472, 4.583, 4.69, 4.796, 4.899, 5
	};
	

	// Variables pour TestB
	char *FileNameB = "Ex23DonB.txt";
	unsigned short lettre = 0;
	char search = 0;
	
	

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

				fp1 = fopen("Ex23ResA.txt", "w");
				
				for (char i = 1; i < 26; i++)
				{
					fprintf(fp1, "I= %02d sqrt = %.3f\n", i, tab[i]);
					printf(" I = %02d sqrt = % .3f\n", i, tab[i]);
				}
				fclose(fp1);
				
                printf("TestA: Le fichier %s est en principe OK !\n", FileNameA);
			break;

			case 'B':
			case 'b':
				// Test B
				printf("TestB: entrez la lettre a rechercher dans le fichier %s ! \n", FileNameB);
				scanf_s("%c%*c", &search, 2);

				fp1 = fopen("Ex23DonB.txt", "r");
				if (fp1 == NULL)
				{
					printf("Erreur ouverture du fichier");
				}
				else
				{
					lettre = FtestB(fp1, search);

					printf("La lettre %c apparait %d fois\n", search, lettre);
				}

				fclose(fp1);

			break;

			case 'C':
			case 'c':
				// Test C
				printf("TestC: Traitement du contenu du fichier %s ! \n", FileNameC);
				// Ouverture du fichier
				fp1 = fopen("Ex23DonC.bin", "rb");
				S_TestC TestC;

				if (fp1 == NULL)
				{
					printf("Erreur ouverture du fichier");
				}
				else
				{
					do
					{
						fread(&TestC, sizeof(TestC), 1, fp1);
						printf("Valeur = %04d Racine = %.3f\n", TestC.Valeur, TestC.RacineValeur);
					} while (feof(fp1) == 0);
				}
				fclose(fp1);
			break;

			case 'Q':
			case 'q':
				sortie = 1;
			break;
		}
	
	} while (sortie == 0);

	return (0);
}