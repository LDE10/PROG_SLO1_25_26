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
fputs() va écrire une chaine de caractère
fputc() va écrire UN caractère 
*/

/*
fscanf() va lire du texte
fread() va lire du binaire
fgets() va lire du text
fgetc() va lire du texte et du binaire
*/

// Pour se situer dans un fichier
fseek() / ftell() / rewind()

/*
fseek() 
ftell() se situe avec le nombre d'octet déplacé
rewind() même chose que le fseek() MAIS si il ne trouve pas il envoie un message d'erreur
*/
