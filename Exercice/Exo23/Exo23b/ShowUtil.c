#include "ShowUtil.h"
#include <stdio.h>

int ShowHex(char* FileNameA)
{
	FILE *fp1;
	int status = 1;
	unsigned char tab[100];
	char calc = 0;

	fp1 = fopen(FileNameA, "rb");

	for (char i = 0; i < 9; i++)
	{
		for (char i = 0; i < 10; i++)
		{
			fread(&tab[i], sizeof(char), 1, fp1);
			printf("%02X ", tab[i]);
		}
		for (char i = 0; i < 10; i++)
		{
			if (tab[i] < 0x20)
			{
				printf("* ");
			}
			else
			{
				printf("%c ", tab[i]);
			}

			if (i == 9)
			{
				printf("\n");
			}
		}
	}

	fclose(fp1);
	return status;
}

int ShowInt16(char* FileNameB)
{
	FILE* fp1;
	int status = 1;
	char count = 0;
	short tab = 0;

	fp1 = fopen(FileNameB, "rb");

	do
	{
		tab = getc(fp1);
		if (tab == 0)
		{
			printf(" ");
		}
		else
		{
			printf("%d ", tab);
		}
		count++;

		if (count == 10)
		{
			printf("\n");
			count = 0;
		}
		else if ((count < 10) && (tab == EOF))
		{
			printf("0\n");
		}

	} while (tab != EOF);
	
	fclose(fp1);
	return status;
}

int ShowFloat(char* FileNameC)
{

}

