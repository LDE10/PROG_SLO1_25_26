// Canevas Exercice 22 fichier aléatoire
// Auteur C. Huber  
//
// Réalisation exercice par :
// Nom Prénom

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	// pour les fonctions fichiers

int main(void)
{
	FILE *fp1;	// descripteur de fichier 
	char *FileName1 = "Ex22_Alire.bin"; 
	char rep;

	// a Adapter
	printf ("Ex22 Nom Prenom \n");

	// Ouverture pour lecture en binaire
	fp1 = fopen (FileName1, "rb");
	if (fp1 == NULL) {
		printf ("Impossible d'ouvrir le fichier %s ! \n", FileName1);
	} else {
		printf ("Lecture du fichier %s \n", FileName1);


		// Introduisez ICI le traitement des éléments [7], [51] et [77]:
	
		
		// Introduisez ICI la détermination de la longueur du fichier


		fclose (fp1); // fermeture du fichier
	}

	// Pour observation
	printf("Enter pour terminer \n");
	scanf_s("%c", &rep, 1);
	return (0);
}
