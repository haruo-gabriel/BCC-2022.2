section .bss                        ;Locais onde serao armazenadas algumas variaveis ao longo do codigo:
    input resb 16                   ;   Input em string
    tipo resb 1                     ;   Tipo de operacao
    n resb 16                       ;   Numero inteiro do input
    p resb 16                       ;   Numero a ser testado em subrotina _primo
    testaPrimo resb 1               ;   Flag utilizada em subrotina _primo
    sup resb 16                     ;   Representa ponto de parada em while como p/2
    sup2 resb 16                    ;   Representa ponto de parada em while como n/2
    output resb 32                  ;   Guarda a string que sera a saida em _print
    posOutput resb 8                ;   Serve como contador auxiliar na funcao _print 

section .text

global _start           

_start:
    
    call _input                     ;Inicia o input do usuario

    cmp byte [tipo], 0              ;A variavel tipo armazena qual modo de operacao sera realizada, essa comparacao e salto serve como condicional formal
    je t0

    call _tipo1
    jmp final                       ;Salto para após a realizacao do _tipo1 nao realizar tambem o _tipo0

t0:                                 ;Aqui se inicia a operacao do tipo 0
    call _tipo0
    mov eax, dword [p]              ;Apos encontrar um primo maior que n, armazena p em eax pois a funcao print imprime o registrador rax
    call _print                     

final:                              ;Nesse bloco final simplesmente é feita a syscall para encerrar o codigo
    mov rax, 60         
    mov rdi, 0          
    syscall             

_input:                             ;Aqui se inicia a funcao de input e transformacao de string em inteiro

    mov rax, 0                      ;Nesse primeiro bloco e feito input em string por syscall e armazenado na variavel 'input'
    mov rdi, 0          
    mov rsi, input      
    mov rdx, 16        
    syscall  

    mov rcx, input                  ;Como a transformacao de string para inteiro sera feita byte a byte, rcx guarda o endereco de memoria da variavel 'input'

    mov bl, byte [rcx]              ;O primeiro byte da entrada representa o tipo, entao primeiro se armazena o byte em bl
    sub bl, '0'                     ;e em seguida, subtrair o valor de '0' da tabela ASCII para obter o inteiro em questão
    mov byte [tipo], bl             ;para então ser armazenado na variavel do tipo

    inc rcx                         ;E necessario incrementar rcx duas vezes pois o primeiro byte ja foi utilizado e o segundo e um espaco vazio
    inc rcx

    xor rbx, rbx                    ;Zerar rbx e a variavel n para nao dar problema na traducao em string
    mov dword [n], 0                

    while:                          ;De forma geral esse laco multiplica o valor atual de n por 10, e soma o valor do proximo byte
    
        cmp byte [rcx], '0'         ;Comparando o contador dessa maneira, o laco encerra quando encontra NULL
        jl fim
        
        mov rax, 10             
        mul dword [n]
        mov [n], rax

        mov bl, byte [rcx]          ;Aqui novamente, antes de salvar o valor do byte atual, subtrai o valor de '0' para obter o inteiro em questao
        sub bl, '0'
        add [n], rbx

        inc rcx
        jmp while

        fim:           
            ret

_primo:                                 ;Funcao que testa se um numero p e primo tentando dividi-lo pelos inteiros de 2 a p/2

    mov byte [testaPrimo], 1            ;A variavel 'testaPrimo' representa o resultado da subrotina, o valor comeca como 1 pois o laco para
                                        ;somente para ao encontrar um dividor, onde recebe 0, ou ao ultrapassar p/2, se mostrando primo
    
    xor edx, edx                        ;Deve-se zerar edx para evitar erros em divisoes em edx:eax

    mov eax, [p]                        ;Como o laco abaixo para em p/2, a variavel sup recebe p/2
    mov ebx, 2
    div ebx
    mov [sup], eax

    mov rcx, 2
    inicio:
        cmp rcx, [sup]                  ;Ao passar de p/2 o laco se encerra e a subrotina retorna 'testaPrimo' como 1
        jg senao2

        xor edx, edx                    ;Divide o numero pelo contador e armazena o resto em edx
        mov eax, [p]
        div rcx

        cmp edx, 0                      ;Caso o numero seja divisivel o resto sera 0 e o numero nao e primo, retornando 'testaPrimo' como 0 
        je senao1

        inc rcx
        jmp inicio

        senao1:
            mov byte [testaPrimo], 0
            ret

        senao2:
            ret

_tipo0:                                 ;Subrotina que busca o proximo primo testando com a subrotina anterior ate encontra-lo

    mov byte [testaPrimo], 0            ;Para iniciar o laco deve-se zerar testaPrimo para a comparacao inicial
    mov ebx, dword [n] ;Como a variavel que de fato sera testada e p, entao o valor de n e passado para p
    mov dword [p], ebx

    while1:

        cmp byte [testaPrimo], 1        ;Caso 'testaPrimo' seja 1 a subrotina retorna o primo em p
        je senao3

        inc dword [p]                   ;Primeiro se incrementa p, pois inicialmente p vale n, e entao chama a subrotina que testara se p e primo
        call _primo

        jmp while1

        senao3:
            ret

_tipo1:                                 ;Subrotina que verifica se certo numero e produto diretamente de dois primos, testando se algum numero entre 2 e n/2 no r8 divide n e em seguida testando se r8 e n/r8 sao primos
    mov r8, 2
    xor edx, edx

    mov eax, [n]                        ;Variavel sup2 recebe n/2 para servir de parada no laco
    mov ebx, 2
    div ebx
    mov [sup2], eax

    while2:

        cmp r8, [sup2]                  ;Ao passar de n/2 a subrotina retorna e nao imprime nada
        jg senao4

        xor edx, edx

        mov eax, [n]                    ;Dividimos n por r8 para receber em edx o resto da divisao
        div r8

        cmp edx, 0                      ;Se o resto for diferente de zero, incrementamos r8 e chamamos o laco novamente
        jne senao5

        mov [p], r8                     ;Ao colocar r8 em p e chamar _primo recebemos em 'testaPrimo' se o numero e primo
        call _primo

        cmp byte [testaPrimo], 0        ;Se nao for primo, incrementamos r8 e chamamos o laco novamente
        je senao5

        xor edx, edx

        mov eax, [n]                    ;Aqui colocamos o resultado da divisao de n por r8 em p, e testamos se e primo
        div r8
        mov [p], eax
        call _primo

        cmp byte [testaPrimo], 0        ;Se nao for primo, incrementamos r8 e chamamos o laco novamente
        je senao5

        xor rax, rax                    ;O programa so chega nessa etapa se encontrar os dois divisores primosentao chamamos a subrotina _print
        mov rax, r8                     ;entao chamamos a subrotina _print com r8 em rax e retornamos
        call _print
        ret

        senao4:

            ret

        senao5:

            inc r8

            jmp while2

_print:                         ;A subrotina _print imprime rax da seguinte maneira, primeiro montamos a string de tras para frente em 'output'
                                ;traduzindo inteiro para, e em seguida essa posicao de memoria e impressa byte a byte tambem de tras para frente

    mov rcx, output             ;Primeiro rcx recebe a posicao de memoria de output, em seguida para termos uma quebra de linha no final colocamos
    mov rbx, 10                 ;10 na primeira posicao
    mov [rcx], rbx

    inc rcx                     ;Como 'posOutput' serve como um contador auxiliar para sabermos onde estamos na string durante o laco final de
    mov [posOutput], rcx        ;impressao, incrementamos rcx e copiamos seu valor em posOutput

    call _while3                ;Chama o laco que copia de tras para frente rax em 'output'

    cmp byte [tipo], 0          ;O print do tipo 0 e do tipo 1 são diferentes, pois no segundo são impressos 2 numeros
    je tipoPrint0               ;Entao e feita uma condicional

    mov rbx, 32                 ;Caso o tipo seja 1, rcx recebera 32, que representa ' ' na tabela ASCII
    mov [rcx], rbx

    inc rcx                     ;E necessario encrementar rcx pois acabamos de adicionar outro digito em 'output'
    mov [posOutput], rcx

    xor edx, edx

    mov eax, dword[n]           ;Agora para imprimir o outro numero pegamos o resultado de n/r8 em eax e chamamos novamente a subrotina que guarda em 'output'
    div r8
    
    call _while3

tipoPrint0:                     ;Caso o tipo for 0, simplesmente seguimos para a impressao propriamente dita

    call _while4
    ret

_while3:                        ;Conforme dito anteriormente, esse laco pega byte a byte rax e coloca de tras para frente em 'output1'

    xor rdx, rdx

    mov rbx, 10                 ;Ao dividir rax por 10 o resto, ou seja, o digito menos significativo em rdx
    div rbx                     

    add rdx, 48                 ;Adicionamos 48 antes de guardar o byte pois 48 representa o zero na tabela ASCII
 
    mov rcx, [posOutput]        ;Após isso, armazena-se o byte na posicao atual da string
    mov [rcx], dl

    inc rcx
    mov [posOutput], rcx
      
    cmp rax, 0                  ;Quando rax for 0 significa que o numero que estava la ja foi passado para a memoria e retornamos
    jne _while3

    ret
 
_while4:                        ;Subrotina que imprime byte a byte de tras para frente a string em 'output'

    mov rax, 1                  ;Syscall para impressao do endereço posOutput
    mov rdi, 1
    mov rsi, [posOutput]
    mov rdx, 1
    syscall
 
    mov rcx, [posOutput]        ;Decrescimento de posOutput para pegar o proximo caracter
    dec rcx
    mov [posOutput], rcx
 
    cmp rcx, output             ;Essa comparacao para o codigo quando a posicao apontada por 'posOutput' for menor que a posicao apontada por 'output' 
    jge _while4
 
    ret