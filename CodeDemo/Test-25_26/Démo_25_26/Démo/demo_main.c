//--------------------------------------------------------------------------//
// Nom du projet		: Démo_25_26
// Nom du fichier		: Démo.C
// Date de création		: 29.09.2025
// Date de modification : 03.11.2025
//
// Auteur				: LDE
//
// Version				: 0.1
//
// Description			: Démo de programme
//
//
// Remarques :
//--------------------------------------------------------------------------//
//-- librairie standard --//
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "Conversion.h"

//-- librairie perso --//
//#include ""					"" -> pour chercher une librairie dans son dossier

//-- définition--//
#define FOIX_2 2
#define PI 3.14

//-- constante globale --//



//--------------------------------------------------------------------------//
//-- Programme principal =>
//-- nom fonction : main
//-- paramètre entrée : -
//-- paramètre sortie : -
//-- paramètre IN-OUT : -
//-- description	  : programme principal =>
//--------------------------------------------------------------------------//
void main() 
{
	//-- constante  --//
	//-- reel
	//-- à évite -> si possible -> raison gestion mémoire
	//const float PI_v1 = 3.14;

	//-- variable--//
	//-- Entier standard
	//-- Signé (+/-)
	char		varchar1;	// 1 octet						/ 8 bits
	short		varshort1;	// 2 octet						/ 16 bits
	int			varint1;	// 4 octet   1 int = 1 long		/ 32 bits
	long long	varlong1;	// 8 octet						/ 32 bits

	//-- Non signé (+)
	unsigned char		varchar2;	// 1 octet						/ 8 bits
	unsigned short		varshort2;	// 2 octet						/ 16 bits
	unsigned int		varint2;	// 4 octet   1 int = 1 long		/ 32 bits
	unsigned long long	varlong2;	// 8 octet						/ 32 bits

	//-- Entier normalisé -> librairie stdint.h
	//-- Signé (+/-)
	int8_t		varchar3;	// 1 octet
	int16_t 	varshort3;	// 2 octet
	int32_t 	varint3;	// 4 octet   1 int = 1 long
	int64_t  	varlong3;	// 8 octet

	//-- Non signé (+)
	uint8_t		varchar4;	// 1 octet
	uint16_t 	varshort4;	// 2 octet
	uint32_t 	varint4;	// 4 octet   1 int = 1 long
	uint64_t  	varlong4;	// 8 octet

	//-- type entier type booléen --//
	bool varS;	// 1 octet
	
	printf("Taille d'un booleen %d [Octet]\n", sizeof(varS));

	//-- définition d'un type enumeration locale --//
						//ETAT_1 = 0, ETAT_2 = 20, ETAT_3 = 21
	enum e_machineEtat { ETAT_1, ETAT_2 = 20, ETAT_3 };

	enum e_machineEtat mE = ETAT_2;

	printf("Taille de l'enum e_machineEtat %d [Octet]\n", sizeof(mE));

	//-- utilisation d'une enumeration globale --//

	e_FORME formeGeo = RECTANGLE;

	printf("Taille de l'enum e_FORME %d [Octet]\n", sizeof(formeGeo));


	//-- Reel
	float		varfloat;		// 4 octet		/ 32 bits
	double		vardouble;		// 8 octet		/ 64 bits
	long double  varlongdouble; // 10 octet		/ 80 bits




	float rayon_m = 10;			// _m => metre
								// cast implicite -> entier -> reel
	float perimetre_m1 = 0, perimetre_m2 = 0, perimetre_m3 = 0;


	//-- une instruction est composé d'opérandes (variables) et d'opérateur (signe) --//
	//cast => (type)variabel
	perimetre_m1 = (float)FOIX_2 * (float)PI * rayon_m;

	// attention au cast implicite
	perimetre_m2 = (float)(FOIX_2 * PI * rayon_m);		// le résultat devient float pas les constantes

	//-- appel de fonction
	//--> calcul perimetre cercle
	perimetre_m3 = CalculPerimetreCercle(rayon_m);

	//--> printf
	printf("%f \n%f \n%f \n", perimetre_m1, perimetre_m2, perimetre_m3);


	// variable ++ = post incrémentation
	// -- variable = pre incrémentation
	// varj += 1; veut dire varj = varj + 1;
	 

	//-- machine état --//
	switch (formeGeo)
	{
	case CERCLE :
		//-- instruction 1
		//-- instruction 2
		break;

	case TRIANGLE:
		//-- instruction 1
		//-- instruction 2
		break;

	case RECTANGLE :
	case CARRE :
		//-- instruction 1
		//-- instruction 2
		break;

	default :
		break;
	}

	//-- itération --//
	//-> 1) condition 2) exécution si c'est vrai
	//-- boucle infinie
	while (1)
	{ }

	uint8_t i = 0, j = 100;
	while (i < j)
	{
		i++;
		j--;
	}

	//-- au minimum 1 fois dans la boucle
	do
	{
		i++;
		j--;

	} while (i < j);

	//-- pour les compteurs --> le développeur connait le nombre d'itération
	//-- boucle à l'infini
	for (;;) 
	{
	}

	//-> 1) initialisation plusieur variables 2) conditions 3) opération
	for (i = 0, j = 100; i < j ; i++, j--)
	{
	}


}


