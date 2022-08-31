#include <stdio.h>

/* Protótipo das funções */
int collatz (int n);

/* Funções */
int main (){
	int i, f;
    FILE *inputf = fopen("input.txt", "r"); 
    FILE *outputf = fopen("output.txt", "w");

	/*printf("Digite o primeiro e o último número do intervalo, separados por um espaço: ");*/
	fscanf(inputf, "%d %d", &i, &f);

	for (int x = i; x <= f; x++){
		fprintf(outputf, "%d\n", collatz(x));
	}

    fclose(inputf); fclose(outputf);
		
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