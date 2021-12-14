#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40

int main() 
{
	char s[SIZE][80];
	char *p[SIZE], *buff;
	FILE *pf;
	int i, j, n = 0;
	pf = fopen("FOR SEM4_3_fileA.txt", "rt");
	if (pf== NULL) 
	{
		printf("\nОшибка открытия файла!");
		return 0;
	}
	while (true) 
	{
		fscanf(pf, "%s", &s[n][0]);
		p[n++] = &s[n][0];
		if (n> SIZE - 1||feof(pf)) break;
	}
	for (i = 0; i<n - 1; i++)
		for (j = i + 1; j<n; j++) 
		{
			if (_stricmp(p[i], p[j])>0)
			{
				buff = p[i]; 
				p[i] = p[j];
				p[j] = buff;
			}
		}
	fclose(pf);
	pf = fopen("FOR SEM4_3_fileB.txt", "wt");
	if (pf == NULL)
	{
		printf("\nОшибка открытия файла");
		return 0;
	}
	for (i = 0; i<n; i++) fprintf(pf, "%s\n", p[i]);
	fclose(pf);
	fflush(stdin); getchar(); return 0;
}