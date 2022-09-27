#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "pilha.h"
#include "palcruz.h"

/* Como compilar:

gcc -Wall -ansi -pedantic -O2 main.c pilha.c matriz.c -o a

*/

int main(){
    int m, n, p; /* m: numero de linhas, n: numero de colunas, p: numero de palavras */

    int **matrizNumeros;
	/*
	Legenda da matriz:
		- celula com -1: espaco indisponivel
		- celula com 0: espaco virgem
		- celula com 1: espaco ocupado com palavra horizontalmente
		- celula com 2: espaco ocupado com palavra verticalmente
		- celula com 3: espaco ocupado com palavra horizontalmente e verticalmente
	*/

    palavras *vocabulario; /* vetor de palavras */ 
    
    /*
    FILE *finput = finput = fopen("input.txt", "r");
    if (finput == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }
    */

    while(1){
        /* INPUT DO USUARIO */
        /*fscanf(finput, "%d %d", &m, &n);*/
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0)
            break;
        
        matrizNumeros = alocaMatriz(m, n);
        leMatriz(matrizNumeros, m, n);
        imprimeMatriz(matrizNumeros, m, n);

		
        /*fscanf(finput, "%d", &p);*/
        scanf("%d", &p);
		vocabulario = malloc(p * sizeof(palavra));

        if (m >= n)
            lePalavras(vocabulario, p, m);
        else
            lePalavras(p, n);









        /* FINALIZACAO DA RODADA*/
        liberaMatriz(matrizNumeros, m);
    }

    /*fclose(finput);*/

    return 0;
}


/* Percorrendo a matrizNumeros linha a linha */
for (i = 0; i < m; i++){
	for (j = 0; j < n; j++){
		if (matrizNumeros[i][j] == 0){ /* Procedimento para o primeiro caso de matrizNumeros[i][j] == 0 */
			if (j < n - 1 && matrizNumeros[i][j+1] == 0){
				tamanhoLinha = contaTamanhoLinha(matrizNumeros, n, i, j);
				
				encaixaPalavraLinha(tamanhoLinha);

				for (l = j; l < j + tamanhoLinha; l++){
					contaTamanhoColuna()
					encaixaPalavraColuna()
					procuraPalavra()
				}

			}
			else if (i < m - 1 && matrizNumeros[i+1][j] == 0){
				tamanhoColuna = contaTamanhoColuna(matrizNumeros, m, i, j);
			}
		}
	}
}

/* Conta o espaco disponivel na linha ate um -1 ou ate a linha acabar */
int contaTamanhoLinha(int **matrizNumeros, int colunas, int linhaAtual, int colunaAtual){
    int j, tamanho;
    
    tamanho = 0;

    for (j = colunaAtual; j < colunas; j++)
        if (matrizNumeros[linhaAtual][j] != -1){
            tamanho++;
			break;
		}

	return tamanho;
}

/* Procura uma palavra com um tamanho especifico */
palavra procuraPalavra(int tamanhoLivre, vocab voc, int nPalavras){
	palavra *p;

	/* Buscando em vocab alguma palavra com tamanho especifico */
	for (i = 0; i < nPalavras; i++ ){
		if (voc->v[0]->)
			return palavra;
	}
}

/* Muda os valores das celulas da matrizNumeros que serao ocupadas pela palavra
e atualiza a posicao da palavra */
void encaixaPalavraColuna(int **matrizNumeros){

	p = procuraPalavra(tamanhoLivre, )

	for (i = linhaAtual; i < linhaAtual + tamanhoLinha; i++){
	}

}

/* Conta o espaco disponivel na coluna ate um -1 ou ate a coluna acabar */
int contaTamanhoColuna(int **matrizNumeros, int linhas, int linhaAtual, int colunaAtual){
    int i, tamanho;
    
    tamanho = 0;

    for (i = linhaAtual; i < linhas; i++)
        if (matrizNumeros[i][colunaAtual] != -1){
            tamanho++;
			break
		}

	return tamanho;
}


