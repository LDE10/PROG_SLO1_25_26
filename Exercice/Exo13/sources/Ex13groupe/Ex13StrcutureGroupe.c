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
	int8_t tnNRZi[11];
};

struct st_temps
{
	int annees;
	int semaines;
	int jours;
	int heurs;
	int minutes;
	int secondes;
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

struct st_tbCode codage(const int8_t tab[], int taille);

struct st_temps ConvSJHMs1(int Time1);
struct st_temps ConvSJHMs2(int Time2);

//-- programme principale --//
void main()
{
	//-- déclaration de variables --// 
	int8_t tbBinaire[TAILLE_TB_BINAIRE] = { 0,1,0,1,0,1,1,0,0,0};

	int Time1 = 654852;	// [s]
	int Time2 = 1225453; // [s]
	 
	struct str_tbInfoRIUP infosRIUP; 

	struct str_trioTR infoCotes; 

	//-- msg pour l'utilisateur --//
	printf("%s %1.1f \n", MSG_BIENVENU, VERSION_CODE); 

	//-- PARTIE A - GROUPE 1 --// 
	//-- appel de la fonction codage --//
	struct st_tbCode code = codage(tbBinaire, TAILLE_TB_BINAIRE);

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
			else if (nbTb == 1)
			{
				printf("%d ", code.tbNRZ[i]);
			}
			//-- affichage tb code NRZi
			else
			{
				printf("%d ", code.tnNRZi[i]);
			}
		}
		//-- retour à la ligne --// 
		printf("\n\n");

	}

	//-- Partie B - Groupe 2 --// 

	//-- appel de la fonction de conversio --// 
	struct st_temps Temps1 = ConvSJHMs1(Time1);
	struct st_temps Temps2 = ConvSJHMs2(Time2);

	//-- affichage MSG user --// 
	printf("Premier Test : temps 1 : %d [s] vaut ", Time1);
	printf("Annee :%d Semaine : %d Jour : %d Heures : %d Minutes : %d Secondes \n", Temps1.annees, Temps1.semaines, Temps1.jours, Temps1.heurs, Temps1.minutes, Temps1.secondes);

	printf("Premier Test : temps 2 : %d [s] vaut ", Time2);
	printf("Annee : %d Semaine : %d Jour : %d Heures : %d Minutes : %d Secondes \n", Temps2.annees, Temps2.semaines, Temps2.jours, Temps2.heurs, Temps2.minutes, Temps2.secondes);

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

struct st_tbCode codage(const int8_t tab[], int taille)
{
	struct st_tbCode result;

	int niveau = 5;

	// NRZ
	for (int i = 0; i < taille; i++)
	{
		if (tab[i] == 1)
		{
			result.tbNRZ[i] = -5;
		}
		else
		{
			result.tbNRZ[i] = 5;
		}
	}

	// NRZi
	result.tnNRZi[0] = 5;   // valeur de départ

	for (int i = 0; i < taille; i++)
	{
		if (tab[i] == 1)
		{
			niveau = -niveau;

			result.tnNRZi[i + 1] = niveau;
		}
	}

	return result;
}

struct st_temps ConvSJHMs1(int Time1)
{
	struct st_temps result;

	// Constantes pour les conversions
	const int SEC_MIN  = 60;
	const int SEC_HOUR = 3600;           // 60 * 60
	const int SEC_DAY  = 86400;          // 24 * 3600
	const int SEC_WEEK = 604800;         // 7 * 86400
	const int SEC_YEAR = 31536000;       // 365 jours


	// Calcul année
	result.annees = Time1 / SEC_YEAR;
	Time1 %= SEC_YEAR;

	// Calcul semaines
	result.semaines = Time1 / SEC_WEEK;
	Time1 %= SEC_WEEK;

	// Calcul jours
	result.jours = Time1 / SEC_DAY;
	Time1 %= SEC_DAY;

	// Calcul heures
	result.heurs = Time1 / SEC_HOUR;
	Time1 %= SEC_HOUR;

	// Calcul minutes
	result.minutes = Time1 / SEC_MIN;
	Time1 %= SEC_MIN;

	// Ce qu'il reste = secondes
	result.secondes = Time1;
	return result;
}

struct st_temps ConvSJHMs2(int Time2)
{
	struct st_temps result;

	// Constantes pour les conversions
	const int SEC_MIN = 60;
	const int SEC_HOUR = 3600;           // 60 * 60
	const int SEC_DAY = 86400;          // 24 * 3600
	const int SEC_WEEK = 604800;         // 7 * 86400
	const int SEC_YEAR = 31536000;       // 365 jours


	// Calcul année
	result.annees = Time2 / SEC_YEAR;
	Time2 %= SEC_YEAR;

	// Calcul semaines
	result.semaines = Time2 / SEC_WEEK;
	Time2 %= SEC_WEEK;

	// Calcul jours
	result.jours = Time2 / SEC_DAY;
	Time2 %= SEC_DAY;

	// Calcul heures
	result.heurs = Time2 / SEC_HOUR;
	Time2 %= SEC_HOUR;

	// Calcul minutes
	result.minutes = Time2 / SEC_MIN;
	Time2 %= SEC_MIN;

	// Ce qu'il reste = secondes
	result.secondes = Time2;

	return result;
}
