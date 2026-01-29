//-----------------------------------------------------------------------------------//
// Nom du projet 		: ExerciceStructure
// Nom du fichier 		: Ex13StrcutureGroupe.c
// Date de création 	: 10.03.2019
// Date de modification : xx.xx.20xx
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : programme principale 
//
//
// Remarques			: lien pour les lib standard:
//						-> https://www.rocq.inria.fr/secret/Anne.Canteaut/COURS_C/annexe.html
//						-> 
//
//----------------------------------------------------------------------------------//

//-- déclaration de librairies systèmes --// 
#include <stdio.h>			// entrée/sortie 
#include <stdlib.h>			// lib standard -> fonctions system 
#include <stdint.h>			// types entiers normalisés

//-- déclration de librairies personnelles --// 

//-- déclaration de définition --// 
#define MSG_BIENVENU		"Ex Structure - Version "
#define VERSION_CODE		0.1
#define TAILLE_TB_BINAIRE	10
#define TAILLE_TB_RIUP		5
#define	NB_TB_AFFICHER		3
#define	VAL_MAX_SECONDE		31449600

//-- déclaration de constantes --// 


//-- déclaration de structure --// 
struct st_tbCode
{
	int8_t tbNRZ[10];
	int8_t tnNRZi[10];
};

struct str_tbInfoRIUP
{
	uint16_t tbR[TAILLE_TB_RIUP];		//	tableau de 5 résitances 
	float	 tbI[TAILLE_TB_RIUP];		//	tableau 5 courant 
	int8_t	 tbU[TAILLE_TB_RIUP];		//	tableau 5 tension 
	float	 tbP[TAILLE_TB_RIUP];		//  tableau 5 Puissance 
};

struct str_trioTR
{
	int8_t	adj, opp, hyp; 
	float	alpha_radian; 
	int16_t aplha_degre; 
};


//-- programme principale --//
void main()
{
	//-- déclaration de variables --// 
	int8_t tbBinaire[TAILLE_TB_BINAIRE] = { 0,1,0,1,0,1,1,0,0,0};

		// Time1 -> 654852	[s]
		// Time2 -> 1225453 [s]
	 
	struct str_tbInfoRIUP infosRIUP; 

	struct str_trioTR infoCotes; 

	//-- msg pour l'utilisateur --//
	printf("%s %1.1f \n", MSG_BIENVENU, VERSION_CODE); 

	//-- PARTIE A - GROUPE 1 --// 

	//-- appel de la fonction codage --//

	//-- affichage des tableaux non codé et codé --// 
	for(int nbTb = 0 ; nbTb < NB_TB_AFFICHER ; nbTb++)
	{
		if (nbTb == 0)
			printf("Tableau binaire : "); 
		else if (nbTb == 1)
			printf("Tableau NRZ : ");
		else 
			printf("Tableau NRZi : ");
		//-- affichage --//
		for (int i = 0; i < TAILLE_TB_BINAIRE; i++)
		{
			//-- affichage tb binaire --//
			if (nbTb == 0)
				printf("%d", tbBinaire[i]); 

			//-- affichage tb code NRZ -- 

			//-- affichage tb code NRZi

		}
		//-- retour à la ligne --// 
		printf("\n\n");

	}

	//-- Partie B - Groupe 2 --// 

	//-- appel de la fonction de conversio --// 

	//-- affichage MSG user --// 
	printf("Premier Test : temps 1 : %%d [s] vaut "); 
	printf("%%d Semaine : %%d Jour : %%d Heures : %%d Minutes : %%d Secondes \n"); 
	printf("Premier Test : temps 2 : %%d [s] vaut ");
	printf("%%d Semaine : %%d Jour : %%d Heures : %%d Minutes : %%d Secondes \n");

	//-- retour à la ligne --// 
	printf("\n\n");

	//-- PARTIE C - GROUPE D --//
	//-- initialisation d'une partie de la structure --//  
	infosRIUP.tbP[0] = 5.5;
	infosRIUP.tbU[0] = -12;

	infosRIUP.tbI[1] = 4.5 * pow(10, -3);
	infosRIUP.tbR[1] = 4200;

	infosRIUP.tbP[2] = 2.5; 
	infosRIUP.tbR[2] = 72 * pow(10, 3);;

	infosRIUP.tbI[3] = .5;
	infosRIUP.tbU[3] = 24;

	infosRIUP.tbI[4] = 1; 
	infosRIUP.tbP[4] = .1;

	//-- appel de la fonction pour calculer la loi ohm sur des tableaux de structure --// 

	//-- afficher les information 4 éléments RIUP pour 5 données --// 
	printf("R = ?? | I = ?? | U = ?? | P = ??"); 

	//-- retour à la ligne --// 
	printf("\n\n");


	//-- PARTIE D - GROUPE 4 --// 
	infoCotes.adj = 5; 
	infoCotes.aplha_degre = 45; 

	printf("cote oppose vaut : "); 
	printf("cote adjacent vaut : ");
	printf("cote hypotenuse vaut : ");
	printf("angle alpha radian : ");
	printf("angle alpha degre : ");

	system("pause");	// -> environnement windows 
}