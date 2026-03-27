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


	printf ("Ex21 Prenom Nom\n");
	
	// 1ère phase 
	// ----------

	// ouverture en lecture binaire du fichier Ex21_1.txt
	
	// Boucle d'affichage en hexa et ASCII du contenu avec fgetc

	// 2ème phase 
	// ----------
	
	// ouverture en écriture binaire du fichier Ex21_2.bin

	// Enregistrement du tableau dans le fichier

	// Sorte de pause
	printf ("Enter pour terminer \n");
	scanf_s("%c", &rep, 1);
	return (0);
}
