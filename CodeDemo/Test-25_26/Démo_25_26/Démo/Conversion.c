//--------------------------------------------------------------------------//
// Nom du projet		: Démo_25_26
// Nom du fichier		: Conversion.c
// Date de création		: 03.11.2025
// Date de modification : XX.XX.20XX
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
#include "Conversion.h"

//--------------------------------------------------------------------------//
//-- nom fonction : CalculPerimetreCercle
//-- paramètre entrée : rayon_m						-> float (Reel)
//-- paramètre sortie : perimetre_m					-> float (Reel)
//-- paramètre IN-OUT : 
//-- description	  : Calculer le perimetre d'un cercle
//--------------------------------------------------------------------------//
float CalculPerimetreCercle(float rayon_m)
{
	//-- déclaration et initialisation const --//
	const float Deux_PI = 2 * 3.14;

	//-- déclaration des variables --//
	float perimetre_m;

	//-- calcul perimetre --//
	perimetre_m = Deux_PI * rayon_m;

	//-- retour perimetre --//
	return (perimetre_m);
}