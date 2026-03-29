// Obligatoire POUR L'UTILISATION
#include <stdio.h>

FILE* fp1 //le FILE indique la gestion de fichier et l'utilisation va se faire avec un pointeur

// Ensuite pour utiliser un fichier il faut fopen("_", _)
// Le "_" sera le nom du fichier avec le racoursi ex: .txt (fichier texte)
// Ensuite mettre soit w (écrire Attention va écraser ce qui est déjà écrit), r (lire) ou a (écrire va écrire juste après ce qui est déja écrit) 
fp1 = fopen("test1.txt", w); 

// Plusieur solution pour les dossiers
fprintf() fscanf() / fputs() fgets() / fputc() fgetc() / fwrite() fread()

// fprintf() va écrire