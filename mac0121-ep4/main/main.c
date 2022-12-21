#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.c"

/* Cria um índice remissivo das palavras de um texto */

int main() {
	noABB *raiz = NULL; /*começo da ABB*/
	char palavra[100], c;
	int linha = 1, i, j;

	while ( (c = getchar()) != EOF ){
		/*coleta uma palavra caracter por caracter*/
		i = 0;
		while (c >= 'A' && c <= 'z'){
			palavra[i] = c;
			i++;
			c = getchar();
		}
		palavra[i] = '\0';

		raiz = insereABB(raiz, palavra, linha);

		if (c == '\n')
			linha++;
		
		/*reinicializa o vetor palavra*/
		for (j = 0; j < 100; j++)
			palavra[j] = 0;
	}

	/*imprime a árvore em ordem cresente em relação às palavras*/
	inordemABB(raiz);

	/*desalocação de memória, obviamente*/
	destroiABB(raiz);

	return 0;
}

