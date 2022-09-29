#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "pilha.h"

/* Como compilar:

gcc -Wall -ansi -pedantic -O2 main.c pilha.c matriz.c -o a

*/

int main(){
    int instancia = 1;

    while(1){ /* colocar conteudo dentro do while */ }

    int m, n, p; /* m: numero de linhas, n: numero de colunas, p: numero de palavras */
    char **matriz;
    /*
    Legenda da matriz:
        - celula com -1: espaco indisponivel
        - celula com 0: espaco virgem
        - celula com 1: espaco ocupado com palavra horizontalmente
        - celula com 2: espaco ocupado com palavra verticalmente
        - celula com 3: espaco ocupado com palavra horizontalmente e verticalmente
    */
    pal *vocabulario; /* vetor de palavras */
    pilha *pilhaPalavras;


    /* INPUT DO USUARIO */
    scanf("%d %d", &m, &n);
    if (m == 0 && n == 0)
        break;
    
    /* Alocacao da matriz */
    matriz = alocaMatrizChar(m, n);
    leMatrizChar(matriz, m, n);
    imprimeMatrizChar(matriz, m, n);

    /* Alocacao da matriz de caracteres 
    matrizChar = alocaMatrizChar(m, n);
    transfereMatrizMatrizChar(matriz, matrizChar, m, n);
    */

    /* Alocacao do array de palavras */
    scanf("%d", &p);
    vocabulario = malloc(p * sizeof(pal));
    lePalavras(vocabulario, p);
    ordenaVocab(vocabulario, p);
    imprimeVocab(vocabulario, p);

    /* Criacao da pilha */
    pilhaPalavras = criaPilha(p);


    cruzada();
    


    /* Impressao */
    printf("Instância %d:\n", instancia);
    imprimeMatrizChar(matriz, m, n);

    /* FINALIZACAO DA RODADA*/
    destroiPilha(pilhaPalavras);
    free(vocabulario);
    liberaMatrizChar(matriz, m);

    return 0;
}

