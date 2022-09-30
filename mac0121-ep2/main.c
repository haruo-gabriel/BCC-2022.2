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
        int m, n, p;
        char **matrizH; char **matrizV;
        pal *voc;
        pilha *pilhaP;


        /* INPUT DO USUARIO */
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0)
            break;
        
        /* Alocacao das matrizes */
        matrizH = alocaMatrizChar(m, n);
        matrizV = alocaMatrizChar(m, n);
        leMatrizChar(matriz, m, n);
        imprimeMatrizChar(matriz, m, n);

        /* Alocacao do voc */
        scanf("%d", &p);
        voc = malloc(p * sizeof(pal));
        lePalavras(voc, p);
        ordenaVocab(voc, p);
        imprimeVocab(voc, p);

        /* Criacao da pilha */
        pilhaPalavras = criaPilha(p);


        haSolucao = cruzadaH(matrizH, matrizV, linhaA, colunaA, m, n);


        /* FINALIZACAO DA RODADA*/
        printf("Instância %d:\n", instancia);
        if (haSolucao){
			mesclaMatrizChar(matrizH, matrizV, m, n);
            imprimeMatrizChar(matrizH, m, n);
		}
        else
            printf('nao ha solucao\n');

        destroiPilha(pilhaP);
        free(voc);
        liberaMatrizChar(matrizH, m);
		liberaMatrizChar(matrizV, m);
    }


    return 0;
}

