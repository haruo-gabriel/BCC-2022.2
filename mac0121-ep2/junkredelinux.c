#include <stdio.h>
#include "pilha.h"

/* NOTAÇÃO
linhas => quantidade absoluta de de linhas da matriz
colunas => quantidade absoluta de colunas da matriz
linhaA => linha atual
colunaA => coluna atual

pal => palavra
nPal => número de palavras no vocabulário
voc => vocabulário/array de todas as palavras
pilhaPal => pilha de palavras

tamLiv => tamanho livre para encaixar uma palavra
*/



/* PENDENCIAS

- verificar se linhaA e colunaA devem ser declarados como ponteiros
- verificar se a pilha deve ser de palavras ou de ponteiros pras palavras do array
- verificar se é possível ajustar todas as funções para elas servirem tanto para a horizontal quanto para a vertical
- verificar se, para a primeira palavra, fazer a busca no main 
- arrumar pseudocódigo

*/



int cruzadaH (char **matrizH, char **matrizV, int linhaA, int colunaA, int linhas, int colunas, pal *voc, pilha *pilhaP){
	int espacoLivre;
	pal *p;


	if (linhaA == linhas && colunaA == colunas)
		return 1;

	if (admitePalH(matrizH, linhaA, colunaA, colunas)){
		espacoLivre = contaEspH(matrizH, linhaA, colunaA, colunas);
		p = procuraPalH(matrizH, matrizV, linhaA, colunaA, colunas, tamLiv, voc, nPal);
		if (p != NULL){
			empilha(pilhaP, *p);
			encaixaPalH();
			incInds(&linhaA, &colunaA, linhas, colunas);

			return cruzadaV(matrizH, matrizV, linhaA, colunaA);
		}
		else{
			if (pilhaVazia(pilhaP))
				return 0;
			else{
				palavra = desempilha(pilhaP);
				deletaPalMatriz ();
				saltaInds(&linhaA, &colunaA, linhas, colunas);

				return cruzadaV(matrizH, matrizV, linhaA, colunaA);
			}
		}
	}
	else
		return cruzadaV();
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
int admitePalH (char **matrizH, int linhaA, int colunaA, int colunas){
	if (matriz[linhaA][colunaA] != '*' && colunaA != colunas){
		if (matriz[linhaA][colunaA+1] != '*'){
			if (colunaA == 0)
				return 1;
			else{
				if (matriz[linhaA][colunaA-1] == '*')	
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


/* Conta o espaço horizontal disponível desde a célula atual até um '*' ou até a linha acabar */
int contaEspH (char **matrizH, int linhaA, int colunaA, int colunas){
    int j, tamanho = 1;

    for (j = colunaA; j < colunas; j++){
        if (matriz[linhaA][j] == '*')
			break;
		tamanho++;
	}
	return tamanho;
}

/* Procura uma palavra com um tamanho específico no array vocabulario para inserí-la horizontalmente */
pal *procuraPalH (char **matrizH, char **matrizV, int linhaA, int colunaA, int colunas, int tamLiv, palavra *voc, int nPal){
	int k, j, encaixa = 1;
	pal p;

	/* Procura todas as palavras com tamanho igual ao tamLiv */
	for (k = 0; k < nPal; k++){
		if (voc[k].len == tamLiv){
			for (j = colunaA; j < colunaA + tamLiv && encaixa; j++){
				if (matrizV[linhaA][j] != '0' && voc[k].string[j] != matrizV[linhaA][j] && voc[k].naPilha != 0) 
					encaixa = 0;
			}

			if (encaixa){
				voc[k].naPilha = 1;
				voc[k].posicao[0] = linhaA;
				voc[k].posicao[1] = colunaA;		
				voc[k].direcao = 0;		
				return voc[k]; /* ou é return &voc[k]? voc[k] é um pointer? */
			}
		}
		else if (voc[k].len > tamLiv)
			return NULL;
	}

	return NULL;
}

void deletaPalMatriz (){

}

/* Muda os índices i, j que percorrem a matriz para a posição da palavra desempilhada no caso de backtracking */
void saltaInds (int *linhaA, int *colunaA, intint linhas, int colunas, pal *p){
	
}

void incInds (int *linhaA, int *colunaA, int linhas, int colunas){
	/* Caso final - percorreu toda a matriz */
	if (*linhaA == linhas - 1 && *colunaA == colunas - 1){
		*linhaA = linhas;
		*colunaA = colunas;
	}

	else{
		if (*linhaA == linhas - 1)
			*linhaA = 0;
		else
			*linhaA++;

		if (*colunaA == colunas - 1)
			*colunaA = 0;
		else
			*colunaA++;
	}
}