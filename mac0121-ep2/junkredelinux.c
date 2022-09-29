#include <stdio.h>
#include "pilha.h"

/* Pseudocodigo 
Checa se a celula da matriz admite palavras na horizontal

Checa se a celula da matriz 
*/

int cruzada(char **matriz, int linhas, int colunas, pilha *pilhaPalavras){
	pal pal;
	int i, j, espacoLivre;
	int linhaAtual, colunaAtual;

    while (linhaAtual < linhas && colunaAtual < colunas){
		iif (admitePalavraHorizontal())

		
	}

}


/* Verifica se a célula da matriz admite palavra horizontalmente
Admite quando:
- a célula não é um '*' e não está na borda direita
e
- a célula da direita não é um '*'
e
(
	- a célula está na borda direita
	ou
	- a célula não está na borda direita, mas a célula à esquerda é um '*'
)
*/
int admitePalavraHorizontal (char **matriz, int linhaAtual, int colunaAtual, int colunas){
	if (matriz[linhaAtual][colunaAtual] != '*' || colunaAtual != colunas){
		if (matriz[linhaAtual][colunaAtual+1] != '*'){
			if (colunaAtual == 0)
				return 1;
			else{
				if (matriz[linhaAtual][colunaAtual-1] == '*')	
					return 1;
				else
					return 0;
			}
		}
		else
			return 0;
	}
	else
		return 0;
}


/* Conta o espaço disponível desde a célula atual até um '*' ou até a linha acabar */
int contaEspacoHorizontal (char **matriz, int linhaAtual, int colunaAtual, int colunas){
    int j, tamanho;
    tamanho = 1;
    for (j = colunaAtual; j < colunas; j++){
        if (matriz[linhaAtual][j] == '*')
			break;
		tamanho++;
	}

	return tamanho;
}

/* Procura uma palavra com um tamanho específico no array vocabulario */
pal *procuraPalavraHorizontal (char **matriz, int linhaAtual, int colunaAtual, int colunas, int tamanhoLivre, palavra *voc, int nPalavra, pal *pal){
	int k, j;
	pal p;

	/* Procura todas as palavras com tamanho igual ao tamanhoLivre */
	for (k = 0; k < nPalavra; k++){
		if (voc[k].len == tamanhoLivre){
			/* Verifica se a palavra encaixa no espaço, letra à letra*/
			for (j = colunaAtual; j < colunaAtual + tamanhoLivre; j++){
				if (matriz[linhaAtual][j] != voc[i].string[j])
					break;
			}
			return voc[i];
		}
	}
	return NULL; 
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