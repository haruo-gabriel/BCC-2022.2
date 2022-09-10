/* 
 * Programa principal.
 * Feito por Gabriel Haruo Hanai Takeuchi 
 * (NUSP: 13671636) para o EP1 da disciplina
 * MAC0121. 
 *
 * Compilado com: gcc -Wall main.c -o main
 */ 

#include <stdio.h>

// Protótipos
long int collatz (int n);

// Funções
int main (){
	long int i, f, num, passos, pot2=2, contPot2=0;
	
    printf("Digite o primeiro número do intervalo: ");
    scanf("%ld", &i);
    printf("Digite o último número do intervalo: ");
    scanf("%ld", &f);

    for (num = i; num <= f; num++){
		// Verifica se n é potência de 2
	    if (num == pot2){
	        pot2 *= 2;
	        contPot2++;
	        passos = contPot2;
	    }

		else
        	passos = collatz(num);

		printf("Número: %ld - Passos: %ld\n", num, passos);
	}

    return 0;
}

long int collatz (int n){
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