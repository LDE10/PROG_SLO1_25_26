/*
Théorie Pointeur fonction
*/

// Exemple 1 changer la valeur des champs d'un autre structure

struct S_ParamA	// Structure
{
	int numerateur;
	int denominateur;
};

struct S_ResA // Structure de sortie de résultat
{
	int rest;
	int resultat;
};

struct S_ResA fDivInt(struct S_ParamA* pt)	// Pointeur sur la structure S_ParamA
{
	struct S_ResA res; // Met la strucutre dans la foncitons pour prendre ou changer les valeurs des champs

	res.rest = pt->numerateur % pt->denominateur;
	res.resultat = pt->numerateur / pt->denominateur;
	return res;
}
struct S_ParamA parametre; // parametre contient l'adresse de S_ParamA

struct S_ResA result = fDivInt(&parametre); // Appel de la fonction fesant un return dans la structure S_ResA en donnant comme valeur d'entrée l'adresse de S_ParamA

/*************************************************************************************************************************************/

// Exemple 2 changer la valeur d'une variable et en même temps dans une fonction

struct S_TestB
{
	int nombre;
	short int unites;
	short int dizaines;
	short int centaines;
};

short int Extract(struct S_TestB* pt) // fonction
{
	short int Units;
	short int nombre = 0;

	Units = pt->nombre % 10;
	pt->centaines = (pt->nombre / 100);
	nombre = pt->nombre % 100;
	pt->dizaines = nombre / 10;
	return (Units);
}

struct S_TestB valeurs;

ResUnit = Extract(&valeurs); // Appel de la fonction fesant un return sur une variable en donnant comme valeur d'entrée l'adresse de S_TestB

/*************************************************************************************************************************************/

// Exemple 3 changer les valeurs d'une stucture avec une fonction contenant un tableau et sa taille

struct st_tbCode //structure
{
	int8_t tbNRZ[10];
	int8_t tnNRZi[11];
};

struct st_tbCode codage(const int8_t tab[], int taille); 

int8_t tbBinaire[TAILLE_TB_BINAIRE] = { 0,1,0,1,0,1,1,0,0,0 };

struct st_tbCode code = codage(tbBinaire, TAILLE_TB_BINAIRE);  // Appel de la fonction fesant un return dans une strucutre en donnant comme valeur d'entrée les valeurs d'un tableau et sa taille

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
	//Le NRZI contrairement au NRZ crée un changement d'état si le bit est 1, et reste à l'état précédent si le bit est 0.
	for (int i = 0; i < taille; i++)
	{
		if (tab[i] == 1)
		{
			result.tnNRZi[i] = 5;
		}
		else
		{
			result.tnNRZi[i] = result.tbNRZ[i];
		}

		if ((tab[0] == 0) && (i == 0))
		{
			result.tnNRZi[0] = 4;
		}
	}
	return result;
} // fonction

/*************************************************************************************************************************************/

// Exemple 4 changer les valeurs d'une structure avec une fonction en entée une valeur

struct st_temps // Structure
{
	int annees;
	int semaines;
	int jours;
	int heurs;
	int minutes;
	int secondes;
};

struct st_temps ConvSJHMs1(int Time1);

struct st_temps Temps1 = ConvSJHMs1(Time1); // Appel de la fonction en entée une variable et en returne une structure 

struct st_temps ConvSJHMs1(int Time1) // fonction 
{
	struct st_temps result;

	// Constantes pour les conversions
	const int SEC_MIN = 60;
	const int SEC_HOUR = 3600;           // 60 * 60
	const int SEC_DAY = 86400;          // 24 * 3600
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

/*************************************************************************************************************************************/

//Exemple 5 modifier les valeurs des champs sous format tableau

#define TAILLE_TB_RIUP		5

struct str_tbInfoRIUP //Structure avec des tableaux comme champs
{
	float	 tbR[TAILLE_TB_RIUP];		//	tableau 5 résitances 
	float	 tbI[TAILLE_TB_RIUP];		//	tableau 5 courant 
	float	 tbU[TAILLE_TB_RIUP];		//	tableau 5 tension 
	float	 tbP[TAILLE_TB_RIUP];		//  tableau 5 Puissance 
};

void LoiOhm(struct str_tbInfoRIUP* pt, int taille);

struct str_tbInfoRIUP infosRIUP; // Adresse de la structure str_tbInfoRIUP dans infosRIUP

LoiOhm(&infosRIUP, TAILLE_TB_RIUP); // Appel de la fonction sans return en donnant en entrée l'adresse de str_tbInfoRIUP et la taille des tableau de champs

void LoiOhm(struct str_tbInfoRIUP* pt, int taille) //fonction avec un pointeur sur str_tbInfoRIUP
{
	for (char i = 0; i <= taille; i++)
	{
		if ((pt->tbI[i] == 0) && (pt->tbR[i] == 0))
		{
			pt->tbI[i] = pt->tbP[i] / pt->tbU[i];
			pt->tbR[i] = (pt->tbU[i] / pt->tbP[i]) * pt->tbU[i];
		}
		else if ((pt->tbU[i] == 0) && (pt->tbP[i] == 0))
		{
			pt->tbU[i] = pt->tbR[i] * pt->tbI[i];
			pt->tbP[i] = (pt->tbR[i] * pt->tbI[i]) * pt->tbI[i];
		}
		else if ((pt->tbU[i] == 0) && (pt->tbI[i] == 0))
		{
			pt->tbU[i] = sqrt(pt->tbP[i] * pt->tbR[i]);
			pt->tbI[i] = sqrt(pt->tbP[i] / pt->tbR[i]);
		}
		else if ((pt->tbR[i] == 0) && (pt->tbP[i] == 0))
		{
			pt->tbR[i] = pt->tbU[i] / pt->tbI[i];
			pt->tbP[i] = pt->tbU[i] * pt->tbI[i];
		}
		else if ((pt->tbU[i] == 0) && (pt->tbR[i] == 0))
		{
			pt->tbU[i] = pt->tbI[i] / pt->tbP[i];
			pt->tbR[i] = (pt->tbP[i] / pt->tbI[i]) * pt->tbI[i];
		}
	}
}

/*************************************************************************************************************************************/

//Exemple 6 changer les valeur d'une structure grace à une fonction qui en son entrée une structure dans une autre structure

struct S_TroisNotes { //Structure
	float NoteTe1;
	float NoteTe2;
	float NoteTe3;
};

struct S_AllNotes { //Structure contenant la structure S_TroisNotes

	struct S_TroisNotes EleveA;
	struct S_TroisNotes EleveB;
	struct S_TroisNotes EleveC;
}; //chaque champs de S_AllNotes contient les 3 champs de S_TroisNotes

struct S_AllMoyennes
{
	float MoyA;
	float MoyB;
	float MoyC;
};

struct S_AllMoyennes CalculAllMoyennes(struct S_AllNotes* pt)
{
	struct S_AllMoyennes moyenne;

	moyenne.MoyA = (pt->EleveA.NoteTe1 + pt->EleveA.NoteTe2 + pt->EleveA.NoteTe3) / 3;
	moyenne.MoyB = (pt->EleveB.NoteTe1 + pt->EleveB.NoteTe2 + pt->EleveB.NoteTe3) / 3;
	moyenne.MoyC = (pt->EleveC.NoteTe1 + pt->EleveC.NoteTe2 + pt->EleveC.NoteTe3) / 3;

	return moyenne;
}

struct S_AllNotes ValA = {
		{5.5, 5.0, 5.0},
		{4.0, 4.5, 5.0},
		{3.5, 4.0, 4.0} };

struct S_AllMoyennes Moyenne = CalculAllMoyennes(&ValA); // Appel de la fonction en return dans une structure et comme entrée un autre structure qui contient lui aussi une autre structure 

/*************************************************************************************************************************************/


