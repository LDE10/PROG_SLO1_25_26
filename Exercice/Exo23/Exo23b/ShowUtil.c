#include "ShowUtil.h"
#include <stdio.h>

int ShowHex(char* FileNameA)
{
	int status;
	int tab[100];
	char calc = 0;

	fopen(FileNameA, "rb");

	for (char i = 0; i < 11; i++)
	{
		fread(&tab[i], sizeof(short), 1, FileNameA);
		printf("%02x ", tab[i]);
	}
	for (char i = 0; i < 11; i++)
	{
		if (tab[i] >= 0x20)
		{
			printf("%c ", tab[i]);
		}
		else
		{
			printf("* ");
		}

		if (i == 10)
		{
			printf("\n");
		}
	}

	fclose(FileNameA);
	return status;
}

int ShowInt16(char* FileNameB)
{

}

int ShowFloat(char* FileNameC)
{

}

