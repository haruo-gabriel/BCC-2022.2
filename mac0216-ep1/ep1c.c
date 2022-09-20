#include <stdio.h>
#include <stdlib.h>

void modo0 (int numero);
void modo1 (int numero);
int ehPrimo (int numero);


int main (){
	int modo, numero;

	scanf("%d %d", &modo, &numero);

	if (modo == 0)
		modo0(numero);
	
	else
		modo1(numero);

	return 0;	
}

void modo0 (int numero){
// Retorna o próximo primo.	
	int i;

	for (i = numero + 1;; i++){
		if (ehPrimo(i)){
			printf("%d\n", i);
			break;
		}
	}
}


void modo1 (int numero){
// Caso numero seja produto de dois primos, imprime-os.
// Caso contrário, não há saída. 
	int i, j, stop;
	stop = 0;

	for (i = 2; !stop && i <= numero/2 && ehPrimo(i); i++){
		j = numero/i;
		if (ehPrimo(j) && i*j == numero){
			printf("%d %d\n", i, j);
			stop = 1;
		}
	}

}

int ehPrimo (int numero){
	int i;

	for (i = 2; i <= numero/2; i++)
		if (numero % i == 0)
			return 0;

	return 1;
}