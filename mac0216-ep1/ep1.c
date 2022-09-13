#include <stdio.h>
#include <stdlib.h>

int modo0 (int n);
void modo1 (int n);
int ehPrimo (int n);


int main (){
	int modo, n;

	scanf("%d", &modo);
	scanf("%d", &n);

	if (modo == 0)
		printf("%d\n", modo0(n));
	
	else if (modo == 1)
		modo1(n);

	return 0;	
}

int modo0 (int n){
// Retorna o próximo primo.	
	int i;

	for (i = n + 1;; i++)
		if (ehPrimo(i))
			return i;
}


void modo1 (int n){
// Caso n seja produto de dois primos, imprime-os.
// Caso contrário, há saída. 
	int i, j, stop;
	stop = 0;

	for (i = 2; !stop && ehPrimo(i) && i <= n/2; i++){
		for (j = n/2; !stop && ehPrimo(j) && j >= 2; j--){
			if (i*j == n){
				printf("%d %d\n", i, j);
				stop = 1;
			}
		}
	}
}

int ehPrimo (int n){
	int i;

	for (i = 2; i <= n/2; i++)
		if (n % i == 0)
			return 0;

	return 1;
}