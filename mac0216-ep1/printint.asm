section .bss
    digitSpace resb 100
    digitSpacePosition resb 8 ; reserving 8 bytes (64 bits) of memory

section .text
    global _start

_start:
    mov rax, 123
    call _printInt

    call _exit

_printInt:
    mov rcx, digitSpace
    mov rbx, 10
    mov [rcx], rbx
    inc rcx
    mov [digitSpacePosition], rcx

_storeInt: ; This loop subroutine stores the digits of the number into the stack
    mov rdx, 0 ; rdx holds the remainder of the operation div rbx
    mov rbx, 10
    div rbx
    push rax
    add rdx, 48

    ; increment digitSpacePosition
    mov rcx, [digitSpacePosition]
    mov [rcx], dl
    inc rcx
    mov [digitSpacePosition], rcx

    pop rax
    cmp rax, 0
    jne _storeInt


_popInt: ; Prints the digits stored on the stack
    mov rcx, [digitSpacePosition]

    mov rax, 1
    mov rdi, 1
    mov rsi, rcx
    mov rdx, 1
    syscall
    
    mov rcx, [digitSpacePosition]
    dec rcx
    mov [digitSpacePosition], rcx

    cmp rcx, digitSpace
    jge _popInt


_exit:
	mov rax, 60
	mov rdi, 0
	syscall
