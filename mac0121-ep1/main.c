#include <stdio.h>
#include <stdlib.h>

#define MAXPASSOS 350
#define MAXNUM 100000

// Protótipo das funções
int collatz (int n, int *pot2, int *contPot2);

// Funções
int main (){
	int i, f, x, pot2=2, contPot2=0;
	
    printf("Digite o primeiro número do intervalo: ");
    scanf("%d", &i);
    printf("Digite o último número do intervalo: ");
    scanf("%d", &f);

    for (x = i; x <= f; x++){
        collatz(i, &pot2, &contPot2);

    	// Impressão de dados
		

	}
    
    

    return 0;
}

int collatz (int n, int *pot2, int *contPot2){
    int cont = 0;

	// Verifica se n é potência de 2
    if (n == *pot2){
        *pot2 *= 2;
        *contPot2++;
        return contPot2;
    }

    // Procedimento padrão da conjectura 
    else{
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
}