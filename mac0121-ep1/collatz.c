//#include "collatz.h"
#include <stdio.h>
#include <stdlib.h>

int collatz (int);
int ehPotDe2 (int, int*, int*);


int main (int argc, char *argv[]){
    printf("%d\n", collatz( atoi(argv[1]) ) );
    return 0;
}

int collatz (int n){
    int cont = 0, pot2=2, contPot2=0;

    /*Como se trata de um intervalo ordenado, então é garantido que 2^x deverá ser calculado antes de 2^(x+1) para todo x natural maior que 0. Dessa forma, tendo n como uma potência de 2, sempre podemos pré-calcular quantos passos a próxima potência de 2 dará. No caso, sempre dará um passo a mais */
    
    if (n == pot2){ // Verifica se n é potência de 2 
        pot2 *= 2;
        contPot2++;
        return contPot2;
    }

    else{ // Procedimento padrão da conjectura
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


