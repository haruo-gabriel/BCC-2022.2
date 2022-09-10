/* 
 * Programa auxiliar (e independente do principal) para a coleta de dados.
 * Como dito no relatório, foi testado o intervalo [1, 100.000].
 * Não há input de usuário, então esse programa funciona apenas para um caso :) 
 * Feito por Gabriel Haruo Hanai Takeuchi (NUSP: 13671636) para o EP1 da disciplina
 * MAC0121.
 * Compilado com: gcc -Wall printcsv.c -o printcsv
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 100000 // Define o intervalo [1, MAXNUM] que será processado por collatz.
#define MAXPASSOS 350 // Define o intervalo [0, MAXPASSOS] para a impressão do arquivo passos_frequencia.csv

/* Protótipo das funções */
int collatz (int);
void printInCSV1(int, int, int *);
void printInCSV2(int *);

/* Funções */
int main (){
    int *observacoes;  // Vetor para o cálculo dos números 
    
    // Inicializacao do vetor observacoes
    freq = malloc(MAXPASSOS * sizeof(int));
    if (observacoes == NULL){
        printf("Memória falhou em ser alocada.\n");
        return 0;
    }
    for (int x = 0; x <= MAXPASSOS; x++)
        freq[x] = 0;

    // Cálculo e impressão
    num_pasCSV(1, MAXNUM, observacoes);
    pas_freqCSV(observacoes);

    // Encerramento do programa
    free(freq);
	return 0;
}

int collatz (int n){
    int cont = 0;

    while (n != 1){
        if (n % 2 == 0){
            cont++;
            n = n/2;    
        }
        else{
            cont++;
            n = 3*n + 1;
        }
    }

    return cont;

}

void num_pasCSV(int start, int end, int *observacoes){
    int cont, i;
    FILE *numpascsv = fopen("numero_passos.csv", "w");

    fprintf(fcsv, "%s,%s\n", "Numero", "Passos");
	for (i = start; i <= end; i++){
        cont = collatz(i);
        observacoes[cont]++;
        fprintf(fcsv, "%d,%d\n", i, cont);
    }

    fclose(numpascsv);
}

void pas_freqCSV(int *observacoes){
	int i;
    FILE *pasfreqcsv = fopen("passos_frequencia.csv", "w");

    fprintf(fcsv, "%s,%s\n", "Passos", "Frequencia");
    for (i = 0; i <= MAXPASSOS; i++)
        fprintf(fcsv, "%d,%d\n", i, observacoes[i]);

    fclose(pasfreqcsv);
}