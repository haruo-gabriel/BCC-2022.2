#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.c"

/* Cria um índice remissivo das palavras de um texto */

int main() {
	noABB *raiz = NULL; /* começo da árvore */
	char palavra[100];
	int linha = 1;

	/*arrumar a leitura de linhas*/
	while (scanf("%[A-Za-z]%*[^a-zA-Z]", palavra) > 0){
		printf("palavra: %s\n", palavra);
		raiz = insereABB(raiz, palavra, linha);
		if (palavra[strlen(palavra)] == "\n")
			linha++;
	}

	preordemABB(raiz);

	destroi(raiz);

	return 0;
}

