// Canevas  Ex19  SL124_LOGA  C. HUBER 


#include <stdio.h>
#include <string.h>  // pour manipulation de String

struct R1
{
	double hauteur;
	double largeur;
	double surface;
};

struct R2
{
	double hauteur;
	double largeur;
	double surface;
};

typedef union 
{
	struct R1 Rectangle1;
	struct R2 Rectangle2;
}U_Rtot;

// Definition S_DefRectangle
typedef struct 
{
	U_Rtot Rectangle;
	char Text1[16];
	char Texte2[16];

}S_DefRectangle;

// Definition S_Frame


// Definition U_Frame


// Fonction ShowInfo


// Fonction ShowFrame


// Programme principal
int main (void)
{
	char UserAnswer;
	// Variables pour test A
	

	// Variables pour test B
	

	// A adapter !!!
	printf("Ex19 Luc Derre \n");

	do {
		printf("Test A ou B, Q pour Quitter \n");
		scanf_s("%c%*c", &UserAnswer, 2);
		
		switch (UserAnswer) {
			case 'A':
			case 'a':
				printf("TestA:  \n");
				// Initialisation champ par champ

				// Pour DefRect1 :  "Surface" , 22.5, 37.2  surface par calcul
				
				
				// Pour DefRect2 :  "Perimetre" , 19.4, 57.1 périmètre par calcul 
				

				// Appel 2x de la fonction pour affichage

				
			break;

			case 'B':
			case 'b':
				printf("TestB:  \n");
				// Frame1 :  Message = "Hello !"
				

				
				// Frame2 :  Message = "Ecole Superieure"
				

				// Affiche la taille de la structure
				
				// Appel de 2x ShowFrame
				
			break;



		} // end switch
	
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));

	return (0);
}