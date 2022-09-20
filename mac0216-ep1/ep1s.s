section .text
    global _start


; int main(){}
_start:

    ; int modo, numero;
	; scanf("%d %d", &modo, &numero);
	; if (modo == 0)
	; 	modo0(numero);
	; else
	; 	modo1(numero);
	; return 0;

    call _scanf

    ; Definição da constante numero/2
    xor edx, edx
    mov eax, [numero]
    mov ebx, 2
    div ebx
    mov [numeroDIV2], eax


    ; if (modo == 0) modo0(numero);
    cmp byte [modo], 0
    je _callmodo0
	
    ; else modo1(numero);
    call _modo1
    mov eax, dword [numeroEhPrimo]              ;Apos encontrar um primo maior que n, armazena p em eax pois a funcao print imprime o registrador rax
    call _printf
    
    call _exit

    _callmodo0:
        call _modo0
        call _exit


   

; void modo0 (int numero){}
_modo0:
    ; for (i = numero + 1;; i++){
	; 	 if (ehPrimo(i)){
	; 		printf("%d\n", i);
	; 		break;
	; 	 }
	; }

    ; Inicialização de variáveis para a chamada de função ehPrimo(i) em void modo0(){}
    mov byte [flagEhPrimo], 0

    mov r8, qword [numero]
    mov qword [numeroEhPrimo], r8

    ;mov ebx, dword [numero]
    ;mov dword [numeroEhPrimo], ebx

    _modo0_loop: ; for (i = numero + 1;; i++)
        cmp byte [flagEhPrimo], 1 ; if (ehPrimo(i))
        je _modo0_break            ;   break;

        inc dword [numeroEhPrimo] ; i++
        call _ehPrimo
        jmp _modo0_loop

        _modo0_break:
            ret


; void modo1 (int numero){}
_modo1:
    mov r8, 1 ; r8 será análogo ao índice i

    ;for (i = 2; !stop && i <= numero/2 && ehPrimo(i); i++){
	;	j = numero/i;
	;	if (ehPrimo(j) && i*j == numero){
	;		printf("%d %d\n", i, j);
	;		stop = 1;
	;	}
	;}

    _modo1_loop:
        ; for (i = 2; !stop && i <= numero/2 && ehPrimo(i); i++)

        inc r8 ; i++

        ; if (i <= numero/2)
        cmp r8, [numeroDIV2]
        jg _modo1_stop

        ; if (ehPrimo(i))
        mov [numeroEhPrimo], r8 
        call _ehPrimo
        cmp byte [flagEhPrimo], 0
        je _modo1_loop

        ; j = numero/i;
        xor edx, edx
        mov eax, [numero]
        div r8
        mov [jModo1], eax


        ; if (ehPrimo(j) && i*j == numero)

        ; if (ehPrimo(j))
        mov [numeroEhPrimo], r9
        call _ehPrimo
        cmp byte [flagEhPrimo], 0
        je _modo1_loop

        ; if (i*j == numero)
        mov rax, r8
        mul r9
        cmp rax, [numero]
        jne _modo1_loop
        

        ; printf("%d %d\n", i, j);
        xor rax, rax
        mov rax, r8
        mov [jModo1], r9
        call _printf

        ;xor rax, rax
        ;mov rax, r9
        ;call _printRAX
        
        ;call _print_linebreak

        _modo1_stop:
            ret


; int ehPrimo (int numero);
_ehPrimo:
    mov byte [flagEhPrimo], 1 ; Valor de retorno da função int ehPrimo(). Neste cógido .s, assume-se valor 1 à flag até que se prove o contrário.

    ; Definição da constante 'numero/2' usado no _ehPrimo_loop
    xor edx, edx
    mov eax, [numeroEhPrimo]
    mov ebx, 2
    div ebx
    mov [numeroDIV2EhPrimo], eax

    mov rcx, 2 ; i = 2

    ; for (i = 2; i <= numero/2; i++)
    _ehPrimo_loop:
        cmp rcx, [numeroDIV2EhPrimo] ; if (i <= numero/2)
        jg _ehPrimo_return1         ;   return 1;

        xor edx, edx
        mov eax, [numeroEhPrimo]
        div rcx

        ; if (numero % i == 0)
        ;     return 0;
        cmp edx, 0 
        je _ehPrimo_return0 

        inc rcx ; i++

        jmp _ehPrimo_loop


        _ehPrimo_return1: ; return 1;
            ret

        _ehPrimo_return0:
            mov byte [flagEhPrimo], 0
            ret


; scanf("%d %d", &modo, &numero);
_scanf:

    ;Nesse primeiro bloco e feito input em string por syscall e armazenado na variavel 'input'
    
    ; sys_read (input)
    mov rax, 0                      
    mov rdi, 0          
    mov rsi, input      
    mov rdx, 16        
    syscall  

    mov rcx, input                  ;Como a transformacao de string para inteiro sera feita byte a byte, rcx guarda o endereco de memoria da variavel 'input'

    mov bl, byte [rcx]              ;O primeiro byte da entrada representa o modo, entao primeiro se armazena o byte em bl
    sub bl, '0'                     ;e em seguida, subtrair o valor de '0' da tabela ASCII para obter o inteiro em questão
    mov byte [modo], bl             ;para então ser armazenado na variavel do modo

    inc rcx                         ;E necessario incrementar rcx duas vezes pois o primeiro byte ja foi utilizado e o segundo e um espaco vazio
    inc rcx

    xor rbx, rbx                    ;Zerar rbx e a variavel numero para nao dar problema na traducao em string
    mov dword [numero], 0                

    while:                          ;De forma geral esse laco multiplica o valor atual de numero por 10, e soma o valor do proximo byte
        cmp byte [rcx], '0'         ;Comparando o contador dessa maneira, o laco encerra quando encontra NULL
        jl fim
        
        mov rax, 10             
        mul dword [numero]
        mov [numero], rax

        mov bl, byte [rcx]          ;Aqui novamente, antes de salvar o valor do byte atual, subtrai o valor de '0' para obter o inteiro em questao
        sub bl, '0'
        add [numero], rbx

        inc rcx
        jmp while

        fim:           
            ret




_printf: ; Imprime rax da seguinte maneira, primeiro montamos a string de tras para frente em 'output' traduzindo inteiro para, e em seguida essa posicao de memoria e impressa byte a byte tambem de tras para frente
    mov rcx, output             ;Primeiro rcx recebe a posicao de memoria de output, em seguida para termos uma quebra de linha no final colocamos
    mov rbx, 10                 ;10 na primeira posicao
    mov [rcx], rbx

    inc rcx                     ;Como 'posOutput' serve como um contador auxiliar para sabermos onde estamos na string durante o laco final de
    mov [posOutput], rcx        ;impressao, incrementamos rcx e copiamos seu valor em posOutput

    call _while3                ;Chama o laco que copia de tras para frente rax em 'output'

    cmp byte [modo], 0          ;O print do modo 0 e do modo 1 são diferentes, pois no segundo são impressos 2 numeros
    je _modo1print               ;Entao e feita uma condicional

    mov rbx, 32                 ;Caso o modo seja 1, rcx recebera 32, que representa ' ' na tabela ASCII
    mov [rcx], rbx

    inc rcx                     ;E necessario encrementar rcx pois acabamos de adicionar outro digito em 'output'
    mov [posOutput], rcx

    xor edx, edx


    ; mov eax, [jModo1]
    mov eax, dword [numero]           ;Agora para imprimir o outro numero pegamos o resultado de numero/r8 em eax e chamamos novamente a subrotina que guarda em 'output'
    div r8
    
    call _while3






_modo1print:                     ;Caso o modo for 0, simplesmente seguimos para a impressao propriamente dita

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



_printRAX:
    mov rcx, digitSpace
    mov rbx, 10
    mov [rcx], rbx
    inc rcx
    mov [digitSpacePos], rcx
 
_printRAXLoop:
    mov rdx, 0
    mov rbx, 10
    div rbx
    push rax
    add rdx, 48
 
    mov rcx, [digitSpacePos]
    mov [rcx], dl
    inc rcx
    mov [digitSpacePos], rcx
    
    pop rax
    cmp rax, 0
    jne _printRAXLoop
 
_printRAXLoop2:
    mov rcx, [digitSpacePos]
 
    mov rax, 1
    mov rdi, 1
    mov rsi, rcx
    mov rdx, 1
    syscall
 
    mov rcx, [digitSpacePos]
    dec rcx
    mov [digitSpacePos], rcx
 
    cmp rcx, digitSpace
    jge _printRAXLoop2
 
    ret




_print_linebreak:
    push   10         ; \n

    push   rsp
    pop    rsi        ; 2 bytes total vs. 3 for mov rsi,rsp

    push   1          ; _NR_write call number
    pop    rax        ; 3 bytes, vs. 5 for mov edi, 1

    mov    edx, eax   ; length = call number by coincidence
    mov    edi, eax   ; fd = length = call number  also coincidence
    syscall           ;   write(1, "\n", 1)

    ret


_exit: ; return 0;
    mov rax, 60         
    mov rdi, 0          
    syscall




section .bss
    input resb 16 ; Input em string
    modo resb 1 ; int modo;
    numero resb 16 ; int numero;
    numeroDIV2 resb 16 ; constante numero/2 usada em diversas funções

    flagEhPrimo resb 1 ; Flag para a função int ehPrimo()
    numeroEhPrimo resb 16 ; Argumento 'numero' da função 'int ehPrimo(int numero)'
    numeroDIV2EhPrimo resb 16 ; Constante 'numeroEhPrimo/2' usada na função 'int ehPrimo(int numero)'

    jModo1 resb 16

    digitSpace resb 100
    digitSpacePos resb 8

    output resb 32 ; Guarda a string que sera a saida em _printf
    posOutput resb 8 ; Serve como contador auxiliar na funcao _printf 