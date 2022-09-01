#include <stdio.h>
#include <stdlib.h>

/* Declaração dos protótipos */
int modoZero (int n);
int modoUm (int n);
int ehprimo (int n);

/* Funções */
int main (){

}

int modoZero (int n){
/* Retorna o próximo primo */

	for (i = n; i > n; i++)
		if (ehprimo(i))
				return i;

}


int *modoUm (int n, int *fator1, int *fator2){
/* Retorna 1 caso existam os dois primos ou 0 caso contrário */

	int i, j;
	int fatores[2];
	for (i = 2; i < ; i++)
		if (ehPrimo(i))
			for (j = 2; j < ; j++)
				if (ehPrimo(j))
					if (n == i * j)
						fatores[0] = i; fatores[1] = j;
						return fatores;
									

}

