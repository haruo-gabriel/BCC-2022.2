#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "pilha.h"

/* COMO COMPILAR
gcc -Wall -ansi -pedantic -O2 main.c pilha.c matriz.c -o a

quando houver apenas os arquivos necessários,
gcc -Wall -ansi -pedantic -O2 *.c -o a

./a
*/

/* NOTAÇÃO
voc => vocabulário - array dos inputs das palavras
*/

int main(){
    int instancia = 1;

    while(1){
        int m, n, p, haSolucao;
        int linhaA, colunaA;
        char **matrizH; char **matrizV;
        pal *voc;
        pilha *pilhaP;


        /* INPUT DO USUARIO */
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0)
            break;
        
        /* Alocacao das matrizes */
        matrizH = alocaMatriz(m, n);
        matrizV = alocaMatriz(m, n);
        leMatriz(matrizH, matrizV, m, n);
        imprimeMatriz(matrizH, m, n);

        /* Alocacao do voc */
        scanf("%d", &p);
        voc = malloc(p * sizeof(pal));
        lePalavras(voc, p);
        ordenaVocab(voc, p);
        imprimeVocab(voc, p);

        /* Criacao da pilha */
        pilhaP = criaPilha(p);


        haSolucao = cruzadaH(matrizH, matrizV, &linhaA, &colunaA, m, n);


        /* FINALIZACAO DA RODADA*/
        printf("Instancia %d:\n", instancia);
        if (haSolucao){
			mesclaMatriz(matrizH, matrizV, m, n);
            imprimeMatriz(matrizH, m, n);
		}
        else
            printf("nao ha solucao\n");

        destroiPilha(pilhaP);
        free(voc);
        liberaMatriz(matrizH, m);
		liberaMatriz(matrizV, m);
    }


    return 0;
}









int cruzadaH (char **matrizH, char **matrizV, int *linhaA, int *colunaA, int linhas, int colunas, int nPal, pal *voc, pilha *pilhaP){
	int tamLiv;
	pal *p;

	if (*linhaA == linhas && *colunaA == colunas)
		return 1;

	if (admitePalH(matrizH, linhaA, colunaA, colunas)){
		tamLiv = contaEspH(matrizH, *linhaA, *colunaA, colunas);
		p = procuraPalH(matrizH, matrizV, *linhaA, *colunaA, colunas, tamLiv, voc, nPal);
		if (p != NULL){
			empilha(pilhaP, p);
			encaixaPalH();
			incInds(linhaA, colunaA, linhas, colunas);

			return cruzadaV(matrizH, matrizV, linhaA, colunaA, linhas, colunas, nPal, voc, pilhaP);
		}
		else{
			if (pilhaVazia(pilhaP))
				return 0;
			else{
				p = desempilha(pilhaP);
				deletaPalMat();
				saltaInds(linhaA, colunaA, linhas, colunas);

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
	if (matrizH[linhaA][colunaA] != '*' && colunaA != colunas){
		if (matrizH[linhaA][colunaA+1] != '*'){
			if (colunaA == 0)
				return 1;
			else{
				if (matrizH[linhaA][colunaA-1] == '*')	
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
        if (matrizH[linhaA][j] == '*')
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

//TODO void deletaPalMat (){

} 

/* Muda os índices que percorrem a matriz para a posição da palavra desempilhada no caso de backtracking */
void saltaInds (int *linhaA, int *colunaA, intint linhas, int colunas, pal *p){
	
}

/* Muda os índices que percorrem a matriz para a próxima célula */
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