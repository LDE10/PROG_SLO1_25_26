// Canevas Exercice 20 fichier text
// Auteur :  C. Huber

// Suppression avertissement C4996
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	// pour fopen, fprintf

int main(void)
{
	char rep;
	FILE *fp1;						// Descripteur de fichier 
	char *FileName = "Ex20.txt";	// Nom du fichier

	char ligne[100];

	char *texte = "Exercice 20 Luc Derre";
	int chiffre = 12345;
	float Nbr = 521.13;

	printf("Fichier %s \n", FileName);
	
	// ouverture pour écriture séquentielle
	fp1 = fopen("Ex20.txt", "w");

	fprintf(fp1,"%s\n%d\n%f\n", texte, chiffre, Nbr);	//écriture dans le fichier
	
	fclose(fp1);

	// 2ème phase relecture
	fp1 = fopen("Ex20.txt", "r");

	while (fgets(ligne, 100, fp1) != NULL)		//Tant que la lecture ne rencontre RIEN continue de lire
	{
		printf("%s", ligne);
	}

	fclose(fp1);

	// Sorte de pause
	printf ("Enter pour terminer \n");
	scanf_s("%c", &rep, 1);
	return (0);
}
