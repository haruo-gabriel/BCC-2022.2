section .data
	text db "Hello, Wordle!",10
	fy db "Fuck you.",10
	no db "NO?",10

section .text
	global _start


_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, text
	mov rdx, 15
	syscall
	;syscall sys_write(1,text,14)

	;jmp _subr

	call _useRet

	mov rax, 60
	mov rdi, 0
	syscall
	;syscall sys_exit(0) just like "return 0;"

_subr:
	mov rax, 1
	mov rdi, 1
	mov rsi, fy
	mov rdx, 10
	syscall
	;syscall sys_write(1,fy,10)

	mov rax, 60
	mov rdi, 0
	syscall
	;syscall sys_exit(0)

_useRet:
	mov rax, 1
	mov rdi, 1
	mov rsi, no
	mov rdx, 4
	syscall
	;syscall sys_write(1,fy,10)
	ret ; ret as "return"
