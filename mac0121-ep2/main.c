#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "pilha.h"

/* Como compilar:

gcc -Wall -ansi -pedantic -O2 main.c pilha.c matriz.c -o a

*/

int main(){
    int m, n, p; /* m: numero de linhas, n: numero de colunas, p: numero de palavras */

    int **matriz;
	/*
	Legenda da matriz:
		- celula com -1: espaco indisponivel
		- celula com 0: espaco virgem
		- celula com 1: espaco ocupado com palavra horizontalmente
		- celula com 2: espaco ocupado com palavra verticalmente
		- celula com 3: espaco ocupado com palavra horizontalmente e verticalmente
	*/

    palavra *vocabulario; /* vetor de palavras */ 

    while(1){
        /* INPUT DO USUARIO */
        /*
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0)
            break;
        
        matriz = alocaMatriz(m, n);
        leMatriz(matriz, m, n);
        imprimeMatriz(matriz, m, n);
        */

        /*fscanf(finput, "%d", &p);*/
        scanf("%d", &p);
		vocabulario = malloc(p * sizeof(palavra));
        lePalavras(vocabulario, p);
        imprimeVocab(vocabulario, p);

        free(vocabulario);

        return 0;









        /* FINALIZACAO DA RODADA*/
        liberaMatriz(matriz, m);
    }

    /*fclose(finput);*/

    return 0;
}

