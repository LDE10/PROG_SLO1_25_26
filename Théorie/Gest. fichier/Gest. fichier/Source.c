<<<<<<< HEAD
#include <stdio.h>	// IMPORTANT pour 

// EN PREMIER
FILE* fp1;

fp1 = fopen
=======
// Obligatoire POUR L'UTILISATION
#include <stdio.h>

FILE* fp1 //le FILE indique la gestion de fichier et l'utilisation va se faire avec un pointeur

// Ensuite pour utiliser un fichier il faut fopen("_", _)
// Le "_" sera le nom du fichier avec le racoursi ex: .txt (fichier texte)
// Ensuite mettre soit w (écrire Attention va écraser ce qui est déjà écrit), r (lire) ou a (écrire va écrire juste après ce qui est déja écrit) 
fp1 = fopen("test1.txt", w); 

// Plusieur solution pour écrire ou lire les dossiers
fprintf() fscanf() / fputs() fgets() / fputc() fgetc() / fwrite() fread()

/*
fprintf() va écrire uniquement dans un fichier texte
fwrite() va écrire du texte MAIS plus utile pour du binaire
fputs() va écrire une chaine de caractère dans un fichier
fputc() permet d'écrire dans un fichier en text ou en binaire
*/

//Exemple :
fprintf(fp1, "ETML\n");
fwirte(Pointeur, sizeof(long), Nbr élement, fp1);
fputs(chaine1, fp1);  //chaine1 = "ETML";
fputc(variableTXT, fp1);

/*
fscanf() va lire du texte
fread() permet de lire un bloc de donnée spécifique
fgets() permet de lire une chaine de caractère dans un fichier ouvert.
fgetc() permet de lire UN caractère dans un fichier en lecture bianire ou texte
*/

//Exemple :
fscanf(fp1, "%s", chaine1);
tableau = fread(Pointeur, sizeof(long), Nbr élement, fp1);
fgets(tableau, NbrMaxCaractère, fp1);
texte = fgetc(fp1);

// Pour se situer dans un fichier
fseek() / ftell() / rewind()

/*
fseek() permet de placer le pointeur de position sur un octet
ftell() connaitre la position relative à partir du début
rewind() se positionne automatiquement au début
*/

//Exemple :
fseek(fp1, offset, SEEK_SET);		//SEEK_SET = Depuis le début; SEEK_CUR = depuis la position actuelle; SEEK_END = Depuis la fin ATTENTION offset doit être à 0 ou négatif pour reculer
variable = ftell(fp1);
frewind(fp1);

fclose(fp1); //Si fini avec le fichier pour fermer le fichier
