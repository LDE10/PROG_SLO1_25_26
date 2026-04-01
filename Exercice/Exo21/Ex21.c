// Canevas Exercice 21 fichiers binaires
// SL124_LOGA
// Auteur C. Huber

// Suppression avertissement C4996
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	// pour fopen, fprintf, fclose, fwrite, fgetc



int main(void)
{
	char rep;
	FILE *fp1;						// Descripteur de fichier 
	// Déclaration et initialisation du tableau
	char *texte = "Exercice 21 Luc Derre";
	int chiffre1 = 1234;
	int chiffre2 = 5678;

	int test;
	char cmpt = 0;
	int tableau1[100];
	int tableau2[10];

	long offset;

	printf ("Ex21 Luc Derre\n");
	
	// 1ère phase 
	// ----------
	fp1 = fopen("Ex21_1.txt", "w");

	fprintf(fp1, "%s\n%d\n%d\n\n", texte, chiffre1, chiffre2);

	fclose(fp1);

	// ouverture en lecture binaire du fichier Ex21_1.txt
	fp1 = fopen("Ex21_1.txt", "rb");

	// Boucle d'affichage en hexa et ASCII du contenu avec fgetc
	for (char i = 0; i < 2; i++)
	{
		for (char i = 0; i < 11; i++)
		{
			tableau1[i] = getc(fp1);
			printf("%02x ", tableau1[i]);
		}
		for (char i = 0; i <= 11; i++)
		{
			printf("%c ", tableau1[i]);
			if (i == 10)
			{
				printf("\n");
			}
			cmpt++;
		}
		if (i == 3)
		{

		}
		if (tableau1[i] < 0x20)
		{
			printf("*");
		}
	}

	fclose(fp1);

	// 2ème phase 
	// ----------
	
	// ouverture en écriture binaire du fichier Ex21_2.bin

	// Enregistrement du tableau dans le fichier

	// Sorte de pause
	printf ("Enter pour terminer \n");
	scanf_s("%c", &rep, 1);
	return (0);
}
