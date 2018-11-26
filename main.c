#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wcfuncs.h"


int main (int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Indique um ficheiro!\n");
		exit(1);
	}
	
	for (int i = 0; i < argc; i++)
	{
		printf("Parametro %d: %s\n", i, argv[i]);
	}
	
	FILE *ficheiro = abreFicheiro(argv[1], "r");
	char *palavra,
		  biggest[128];
	int   counter 		  = 0,
		  fileHasntEnded  = 1;
	do
	{
		palavra = lePalavra(ficheiro);
		fileHasntEnded = !feof(ficheiro);
		if (fileHasntEnded)
		{
			if (counter == 0)
				strcpy(biggest, palavra);
			else if (strlen(palavra) > strlen(biggest))
				strcpy(biggest, palavra);
			
			counter++;
		}
	}
	while (fileHasntEnded);
	
	printf("Numero de palavras : %d", counter);
	printf("\nPalavra maior : %s", biggest);
	fclose(ficheiro);
    return 0;
}

