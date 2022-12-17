#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.c"

/* Cria um índice remissivo das palavras de um texto */

int main() {
	no *index = NULL; /* começo da árvore */
	char palavra[100];
	int linha = 1;

	while (scanf("%[A-Za-z]%*[^a-zA-Z]", palavra) > 0){
		index = insere(index, palavra, linha);
		linha++;
	}

	preordem(index);

	destroi(index);

	return 0;
}

