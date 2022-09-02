#include <stdio.h>
#include <stdlib.h>

#define MAXPASSOS 350
#define MAXNUM 50000

/* Protótipo das funções */
int collatz (int n);
void printInCSV1(char header1[], char header2[], int start, int end, int *observ);
void printInCSV2(char header1[], char header2[], int *observ);
void printInTXT2(int *observ);

/* Funções */
int main (int argc, char *argv[]){
	int i, f;
    int *freq;  // Conta os f[i] numeros que percorreram i passos em um intervalo [0, MAXPASSOS]
    
	
    //printf("Digite o primeiro e o último número do intervalo, separados por um espaço: ");
    //scanf("%d %d", &i, &f);
    i = 1; //atoi(argv[1]);
    f = MAXNUM; //atoi(argv[2]);
    
    // Inicializacao do vetor freq
    freq = malloc(MAXPASSOS * sizeof(int));
    if (freq == NULL){
        printf("Memória falhou em ser alocada.\n");
        return 0;
    }
    for (int x = 0; x <= MAXPASSOS; x++)
        freq[x] = 0;

    // Cálculo e impressão
    printInCSV1("Numeros", "Passos", i, f, freq);
    //printInTXT2(freq);
    printInCSV2("Passos", "Frequencia", freq);


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

void printInCSV1(char header1[], char header2[], int start, int end, int *observ){
    int cont;
    FILE *fcsv = fopen("numero_passos.csv", "w");

    fprintf(fcsv, "%s,%s\n", header1, header2);
	for (int i = start; i <= end; i++){
        cont = collatz(i);
        observ[cont]++;

        fprintf(fcsv, "%d,%d\n", i, cont);
    }

    fclose(fcsv);
}

void printInCSV2(char header1[], char header2[], int *observ){
    FILE *fcsv = fopen("passos_frequencia.csv", "w");

    fprintf(fcsv, "%s,%s\n", header1, header2);
    for (int i = 0; i <= MAXPASSOS; i++)
        fprintf(fcsv, "%d,%d\n", i, observ[i]);

    fclose(fcsv);
}

void printInTXT2(int *observ){
    FILE *fpas_freq = fopen("passos_frequencia.txt", "w");

    fprintf(fpas_freq, "Teste no intervalo [1, %d]\n\nPassos   |   Frequência\n", MAXPASSOS);
    for (int i = 0; i <= MAXPASSOS; i++){
        fprintf(fpas_freq, "%6d       %d\n", i, observ[i]);
    }

    fclose(fpas_freq);

}