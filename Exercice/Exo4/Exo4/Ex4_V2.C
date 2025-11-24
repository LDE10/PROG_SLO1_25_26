//-----------------------------------------------------------------------------------//
// Nom du projet 		: Exo 4
// Nom du fichier 		: Exo 4
// Date de création 	: 17.11.2025
// Date de modification : xx.xx.xxxx
//
// Auteur 				: LDE (Luc Derré)
//                        
//
// Version 				: 0.1
//
// Description          : Voir donnee exercice 4 
//
//
// Remarques :            lien pour la table ASCII :
// 						  -> http://www.asciitable.com/
// 						  
//----------------------------------------------------------------------------------//

//-- déclaration des librairies --// 
#include <stdio.h>	// pour usage printf


int main(void)
{
	// Déclaration cas A
	short A1 = 400;
	short A2 = 500;

	short ResA1 = A1 * A2;
	int ResA2 = A1 * A2;

	// Déclaration cas B
	unsigned short valB = 0x1234;

	unsigned short HighValB = (valB >> 8) & 0xFF;
	unsigned short LowValB = valB & 0xFF;

	// Déclaration cas C
	unsigned C1 = 0x5555;
	unsigned C2 = 0x0F0F;

	unsigned RestC1 = C1 | C2;
	unsigned RestC2 = C1 & C2;

	// Déclaration cas D
	short D1 = 1325;
	short D2 = 7;

	short RestD1 = D1 / D2;
	short RestD2 = D1 % D2;

	// Traitement cas A
	printf ("Traitement cas A \n");

	printf ("ResA1 = A1 * A2 soit  %d * %d = %d \n", A1, A2, ResA1);
	printf ("ResA2 = A1 * A2 soit  %d * %d = %d \n", A1, A2, ResA2);
	// Le résultat du produit de A1 et A2 n'est pas correcte car la variable ResA1 est trop petit pour contenir toute la réponse
	
	
	// Traitement cas B
	printf ("Traitement cas B \n");

	printf ("ValB  %x HighValB = %x LowValB = %x\n", valB, HighValB, LowValB);
	
	// Traitement cas C
	printf ("Traitement cas C \n");

	printf ("ResC = %04x  OU %04x =  %04x \n",C1, C2, RestC1);
	printf ("ResC = %04x  ET %04x =  %04x \n",C1, C2, RestC2);

	// Traitement cas D

	printf ("Traitement cas D \n");

	printf ("Division de %4d par %4d = %4d Reste = %4d \n",D1, D2, RestD1, RestD2);

  return(0);
}
