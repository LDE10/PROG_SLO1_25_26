// Canevas Exercice 20 fichier text
// Auteur :  C. Huber

// Suppression avertissement C4996
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	// pour fopen, fprintf

int main(void)
{
	char rep;
	int chaine[100];
	int chiffre1 = 0;
	float chiffre2 = 0;
	FILE *fp1;						// Descripteur de fichier 
	char *FileName = "Ex20.txt";	// Nom du fichier

	printf("Fichier %s \n", FileName);
	printf ("Ex20 Derre Luc \n");
	
	// ouverture pour écriture séquentielle
	fp1 = fopen("Ex20.txt", "w");

	fprintf(fp1,"Exercice 20 Luc Derre\n%d\n%f", 12345, 521.13);
	
	fclose(fp1);
	// 2ème phase relecture
	fp1 = fopen("Ex20.txt", "r");
	fgets(chaine,100,fp1);
	printf("%s", chaine);
	fclose(fp1);

	fp1 = fopen("Ex20.txt", "r");
	fscanf(fp1, "%d\n \n%f", chiffre1, chiffre2);
	printf("%d\n%f\n", chiffre1, chiffre2);

	fclose(fp1);
	
	// Sorte de pause
	printf ("Enter pour terminer \n");
	scanf_s("%c", &rep, 1);
	return (0);
}
