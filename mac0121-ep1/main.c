/* 
 * Programa principal.
 * Feito por Gabriel Haruo Hanai Takeuchi 
 * (NUSP: 13671636) para o EP1 da disciplina
 * MAC0121. 
 *
 * Compilado com: gcc -Wall main.c -o main
 */ 

#include <stdio.h>

int collatz (int);
int ehPotDe2 (int, int *);

int main (){
	int i, f, num, passos, pot2, contPot2;
	
    printf("Digite o primeiro número do intervalo: ");
    scanf("%d", &i);
    printf("Digite o último número do intervalo: ");
    scanf("%d", &f);

	// Verifica se há uma potência de 2 entre [i, f]
	pot2 = i;
  	while (pot2 < f && !ehPotDe2(pot2, &contPot2))
    	pot2++;
  	contPot2--;

    for (num = i; num <= f; num++){
		// Verifica se n é potência de 2
	    if (num == pot2){
	        pot2 *= 2;
	        contPot2++;
	        passos = contPot2;
	    }

		else
        	passos = collatz(num);

		printf("Número: %d - Passos: %d\n", num, passos);
	}

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

int ehPotDe2(int n, int *contPot2) {
  	*contPot2 = 0;

  	while (n != 1) {
    	if (n % 2 != 0)
      		return 0;
    	n /= 2;
    	*contPot2 = *contPot2 + 1;
  	}

  	return 1;
}