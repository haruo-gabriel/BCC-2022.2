#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "pilha.h"

/* Como compilar:

gcc -Wall -ansi -pedantic -O2 main.c pilha.c matriz.c -o a

*/

int main(){

    instancia = 1;

    while(1){    
        int m, n, p, instancia; /* m: numero de linhas, n: numero de colunas, p: numero de palavras */
        /* int **matriz; */
        char **matrizChar;
        /*
        Legenda da matriz:
            - celula com -1: espaco indisponivel
            - celula com 0: espaco virgem
            - celula com 1: espaco ocupado com palavra horizontalmente
            - celula com 2: espaco ocupado com palavra verticalmente
            - celula com 3: espaco ocupado com palavra horizontalmente e verticalmente
        */
        palavra *vocabulario; /* vetor de palavras */
        pilha *pilhaPalavras;


        /* INPUT DO USUARIO */
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0)
            break;
        
        /* Alocacao da matriz */
        matriz = alocaMatriz(m, n);
        leMatriz(matrizChar, m, n);
        imprimeMatrizChar(matrizChar, m, n);

        /* Alocacao da matriz de caracteres 
        matrizChar = alocaMatrizChar(m, n);
        transfereMatrizMatrizChar(matriz, matrizChar, m, n);
        */

        /* Alocacao do array de palavras */
        scanf("%d", &p);
		vocabulario = malloc(p * sizeof(palavra));
        lePalavras(vocabulario, p);
        imprimeVocab(vocabulario, p);

        /* Criacao da pilha */
        pilhaPalavras = criaPilha(p);


        cruzada();
        


        /* Impressao */
        printf("Instância %d:\n", instancia);
        imprimeMatrizChar(matrizChar, m, n);

        /* FINALIZACAO DA RODADA*/
        destroiPilha(pilhaPalavras)
        free(vocabulario);
        liberaMatriz(matriz, m);
        liberaMatrizChar(matrizChar, m);
    }

    return 0;
}

