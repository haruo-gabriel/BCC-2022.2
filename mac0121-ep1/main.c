#include <stdio.h>

/* Protótipo das funções */
int collatz (int n, int *cont);

/* Funções */
int main (){
	int i, f;
	int *cont;

	printf("Digite o primeiro e o último número do intervalo, separados por um espaço: ");
	scanf("%d %d", &i, &f);

	for (int x = i; x <= f; x++){
		*cont = 0;
		printf("%d passos para entrada %d\n", collatz(x, cont), x);
	}
		
	return 0;
}

int collatz (int n, int *cont){
	if (n == 1)
		return 0;
	else if (n % 2 == 0){
		*cont++;
		return collatz(n/2, cont);
	}
	else{
		*cont++;
		return collatz(3*n + 1, cont);
	}
}