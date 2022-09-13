section .data ;section that memory is preallocated with data
	text1 db "What is your name? "
	text2 db "Hi, "

section .bss ;section that reserves chunks of memory
	name resb 10 ;resb as "reserve bytes" , 10 bytes reserved

section .text
	global _start

_start:
	call _questionName
	call _getName
	call _displayName
	call _printName

	mov rax, 60
	mov rdi, 0
	syscall
	;sys_exit(0) <-> return 0;

_getName:
	mov rax, 0 ;0 is stdin
	mov rdi, 0
	mov rsi, name
	mov rdx, 10
	syscall ;sys_read <-> scanf
	ret

_questionName:
	mov rax, 1 ;1 is stdout
	mov rdi, 1
	mov rsi, text1
	mov rdx, 19
	syscall ;sys_write <-> printf
	ret

_displayName:
	mov rax, 1
	mov rdi, 1
	mov rsi, text2
	mov rdx, 4
	syscall
	ret

_printName:
	mov rax, 1
	mov rdi, 1
	mov rsi, name
	mov rdx, 10
	syscall
	ret
