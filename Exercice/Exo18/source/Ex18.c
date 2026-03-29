// Solution Ex18 24.05.2010 C. HUBER
// 
// Directives de compilation
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	// pour printf
#include <string.h>	// pour strcat


// Programme principal 
int main(void)
{
	char Rep;

	char Text1[40] = "Salut ";
	const char *Text2 = "les copains";

	printf("Ex18 L. DERRE\nText 1 = %s\nText 2 = %s\n", Text1, Text2);

	strcat(Text1, Text2);

	printf("Text 1 = %s\n", Text1);
	printf("Pressez enter pour quitter !");
	scanf("%c", &Rep);

	return (0);
}
