// Canevas Ex13B SL124_LOGA SLO1 2ème semestre
// Maj 26.01.2017 C. Huber


#include <stdio.h>

// type structure fourni
 struct S_TroisNotes {
	float NoteTe1;
	float NoteTe2;
	float NoteTe3;
};

 struct S_AllNotes {

	struct S_TroisNotes EleveA;
	struct S_TroisNotes EleveB;
	struct S_TroisNotes EleveC;
};

// definition du type S_AllMoyennes
struct S_AllMoyennes
{
	float MoyA;
	float MoyB;
	float MoyC;
};

// Fonction CalculAllMoyennes
struct S_AllMoyennes CalculAllMoyennes(struct S_AllNotes *pt)
{
	struct S_AllMoyennes moyenne;

	moyenne.MoyA = (pt->EleveA.NoteTe1 + pt->EleveA.NoteTe2 + pt->EleveA.NoteTe3) / 3;
	moyenne.MoyB = (pt->EleveB.NoteTe1 + pt->EleveB.NoteTe2 + pt->EleveB.NoteTe3) / 3;
	moyenne.MoyC = (pt->EleveC.NoteTe1 + pt->EleveC.NoteTe2 + pt->EleveC.NoteTe3) / 3;

	return moyenne;
}

// Fonction CalculAllMoyTestB
void CalculAllMoyTestB(struct S_AllMoyennes* pt1, struct S_AllNotes *pt2)
{

}


// Programme principal
int main (void)
{
	char UserAnswer;
	// Variables pour test A
	struct S_AllNotes ValA = {
		{5.5, 5.0, 5.0},
		{4.0, 4.5, 5.0},
		{3.5, 4.0, 4.0} };
	
	// Variables pour test B
	struct S_AllMoyennes ResB;

	// Modification de la note 1 de l'élève B à 4.5
	struct S_AllNotes ValB = {
	{5.5, 5.0, 5.0},
	{4.5, 4.5, 5.0},
	{3.5, 4.0, 4.0} };

	// A adapter !!!
	printf("Ex13B Luc Derre \n");
	do {
		printf("Test A ou B, Q pour Quitter \n");
		scanf_s("%c%*c", &UserAnswer, 2);
		
		switch (UserAnswer) {
			case 'A':
			case 'a':
				printf("TestA:  \n");
				// Appel de CalculAllMoyennes
				struct S_AllMoyennes Moyenne = CalculAllMoyennes(&ValA);

				// Affichage des moyennes
				printf("MoyA = %f MoyB = %f MoyC = %f\n", Moyenne.MoyA, Moyenne.MoyB, Moyenne.MoyC);

			break;

			case 'B':
			case 'b':
				printf("TestB:  \n");
				// Appel de CalculAllMoyTestB
				CalculAllMoyTestB(&ResB, &ValB);

				// Affichage des moyennes
				
			break;

		} // end switch
	
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));

	return (0);
}