#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wcfuncs.h"

char * lePalavra(FILE * f)
{
	static char palavra[128]; /* 	assume-se que as palavras do ficheiro
					não têm um comprimento maior que
					MAX. Note que a variável está definida
					como estatic */
	fscanf(f, "%s", palavra);
	return palavra;
}

FILE * abreFicheiro(char * nome, char * mode)
{
	FILE * f;
	printf("A abrir o ficheiro %s\n", nome);
	f = fopen(nome, mode);
	if (f == NULL)
	{
		fprintf(stderr, "*** Não foi possivel abrir o ficheiro %s.", nome);
		exit(1);             /* As mensagens de erro são escritas para o
					canal stderr. Em caso de erro, sair com
					código diferente de 0. */
	}
	return f;
}

