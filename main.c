#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wcfuncs.h"


int main (int argc, char **argv)
{

	for (int i = 0; i < argc; i++)
	{
		printf("Parametro %d: %s\n", i, argv[i]);
	}
	
	FILE *a = abreFicheiro(argv[1], "r");
	char *b,
		  biggest[128];
	int counter 		= 0,
		fileHasntEnded  = 1;
	do
	{
		b = lePalavra(a);
		fileHasntEnded = !feof(a);
		if (fileHasntEnded)
		{
			if (counter == 0)
				strcpy(biggest, b);
			else if (strlen(b) > strlen(biggest))
				strcpy(biggest, b);
			
			counter++;
		}
	}
	while (fileHasntEnded);
	
	printf("Numero de palavras : %d", counter);
	printf("\nPalavra maior : %s", biggest);
        return 0;
}

