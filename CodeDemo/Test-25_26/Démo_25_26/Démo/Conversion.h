//--------------------------------------------------------------------------//
// Nom du projet		: Démo_25_26
// Nom du fichier		: Conversion.h
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

#ifndef CONVERSION_H //-> par convertion nomme le nom du fichier
#define CONVERSION_H

//--Structure globale--//
typedef struct
{
	int gain;
	double Vbe;
	short courant[2];
}str_transistor;

typedef struct
{
	char bit1 : 1;	//Utilisation de 1 bit dans 1 octet
	char bit2 : 2;	//Utilisation de 2 bit dans 1 octet
	char bits : 5;	//Utilisation de 5 bit dans 1 octet
	//Attention on ne peut pas le faire avec des réels
}str_champsbits;

typedef struct
{
	char version : 4;			//LSB
	char longueurEntete : 4;
	char TypeService;
	short longueurTotal;		 //MSB
}str_enteteEthernet;

typedef union
{
	str_enteteEthernet decodageTrame;
	int trame;
}u_ethernet;

//--Prototype--//
void DemoStruct(str_transistor transistor);


//-- Déclaration définition --//

//-- prototype --//
float CalculPerimetreCercle(float rayon_m);

typedef enum { CERCLE, ELLIPSE, CARRE, RECTANGLE, TRIANGLE }e_FORME;


#endif // !CONVERSION_H //-> par convertion nomme le nom du fichier


