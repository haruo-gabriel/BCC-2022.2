#include <stdio.h>
#include "pilha.h"

int cruzada(char **matriz, int linhas, int colunas, pilha *pilhaPalavras){
	palavra pal;
	int i, j, espacoLivre, ok;
	int linhaAtual, colunaAtual;

	ok = 1;
	
	while(ok){

	}

    for (i = 0; i < linhas; i++){
	    for (j = 0; j < colunas; j++){
            /* Checa se a celula da matriz admite palavras na vertical e/ou horizontal */
			posicaoValida = posicaoValida(matriz, i, j, linhas, colunas);

			if (!posicaoValida)
				

			if (posicaoValida == 1){

			}

			if (posicaoValida == 2){

			}

			if (posicaoValida == 3){

			}



			if (posicaoValidaHorizontal(matriz, i, j)){
				espacoLivre = contaEspacoHorizontal(matriz, i, j);
				pal = procuraPalavra(matriz, espacoLivre);
				inserePalavraHorizontal(matriz, i, j, pal);
				empilha(pilhaPalavras, pal);

			}

        }
    }
}



/* Verifica se a celula da matriz admite palavra verticalmente e/ou horizontalmente
return 0 -> invalido tanto pra horizontal quanto pra vertical
return 1 -> valido apenas pra horizontal
return 2 -> valido apenas pra vertical
return 3 -> valido tanto pra horizontal quanto pra vertical; */
int posicaoValida (char **matriz, int linhaAtual, int colunaAtual, int linhas, int colunas){
	int hor = 0, ver = 0;
	if (colunaAtual != colunas && matriz[linhaAtual][colunaAtual] != '*' && matriz[linhaAtual][colunaAtual+1] != '*')
		hor = 1;
	if (linhaAtual != linhas && matriz[linhaAtual][colunaAtual] != '*' && matriz[linhaAtual+1][colunaAtual] != '*')
		ver = 2;
	
	return (hor + ver)
}

/* Deprecated*/
/* Verifica se a celula da matriz admite palavra horizontalmente */
int posicaoValidaHorizontal (char **matriz, int linhaAtual, int colunaAtual, int colunas){
	if (colunaAtual == colunas)
		return 0;
	if (matriz[linha][coluna] != '*' && matriz[linha][coluna+1] != '*')
		return 1;
	return 0;
}

/* Verifica se a celula da matriz admite palavra verticalmente*/
int posicaoValidaVertical (char **matriz, int linhaAtual, int colunaAtual, int colunas){
	if (colunaAtual == colunas)
		return 0;
	if (matriz[linha][coluna] != '*' && matriz[linha+1][coluna] != '*')
		return 1;
	return 0;
}


/* Conta o espaco disponivel na linha ate um -1 ou ate a linha acabar */
int contaEspacoHorizontal (char **matriz, int linhaAtual, int colunaAtual, int colunas){
    int j, tamanho;
    
    tamanho = 2;

    for (j = colunaAtual+2; j < colunas; j++){
        if (matriz[linhaAtual][j] == -1)
			break;
		tamanho++;
	}

	return tamanho;
}

/* Procura uma palavra com um tamanho especifico no array vocabulario */
int procuraPalavra (int tamanhoLivre, palavra *vocabulario, int nPalavras, palavra *){
	int i;
	for (i = 0; i < nPalavras; i++ ){
		if (vocabulario[i].len == tamanhoLivre){
			vocabulario[i].naPilha = 1;
			return vocabulario[i];
		}

		return 
	}
}

int palavraEncaixa (char **matriz, palavra pal, int linhaAtual, int colunaAtual, int linhas, int colunas){

}

void encaixaPalavraHorizontal (char **matriz, int LinhaAtual, int colunaAtual, palavra pal){
	for (j = colunaAtual; j < colunaAtual + pal.len; j++){
		if (matriz[linhaAtual][j] > 0)
	}
}















/* Muda os valores das celulas da matriz que serao ocupadas pela palavra
e atualiza a posicao da palavra */
void encaixaPalavraColuna(int **matriz){

	p = procuraPalavra(tamanhoLivre, )

	for (i = linhaAtual; i < linhaAtual + tamanhoLinha; i++){
	}

}

/* Conta o espaco disponivel na coluna ate um -1 ou ate a coluna acabar */
int contaTamanhoColuna(int **matriz, int linhas, int linhaAtual, int colunaAtual){
    int i, tamanho;
    
    tamanho = 0;

    for (i = linhaAtual; i < linhas; i++)
        if (matriz[i][colunaAtual] != -1){
            tamanho++;
			break
		}

	return tamanho;
}







/* Percorrendo a matriz linha a linha */
for (i = 0; i < m; i++){
	for (j = 0; j < n; j++){
		if (matriz[i][j] == 0){ /* Procedimento para o primeiro caso de matriz[i][j] == 0 */
			if (j < n - 1 && matriz[i][j+1] == 0){
				tamanhoLinha = contaTamanhoLinha(matriz, n, i, j);
				
				encaixaPalavraLinha(tamanhoLinha);

				for (l = j; l < j + tamanhoLinha; l++){
					contaTamanhoColuna()
					encaixaPalavraColuna()
					procuraPalavra()
				}

			}
			else if (i < m - 1 && matriz[i+1][j] == 0){
				tamanhoColuna = contaTamanhoColuna(matriz, m, i, j);
			}
		}
	}
}