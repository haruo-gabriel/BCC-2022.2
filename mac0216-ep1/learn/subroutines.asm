SYS_WRITE equ 1
STDIN equ 0
STDOUT equ 1

section .data
	digit db 0,10
	text db "I am a string of text!",10,0

section .bss


section .text
	global _start


_start:
	; prints the value on rax
	mov rax, 4
	mov rbx, 2
	mul rbx
	call _printRAXdigit ; should print 8

	
	; prints the string in "text"
	mov rax, text
	call _print



	call _return0


; # Subroutines

; move a single digit to RAX and call the subroutine
_printRAXdigit:
	add rax, 48 ; the number 0 in ASCII table is code 48
	mov [digit], al ; "al" has the 8 least significant bits
			; (or first least significant byte) of rax
	
	mov rax, SYS_WRITE
	mov rdi, STDOUT
	mov rsi, digit
	mov rdx, 2
	syscall
	
	ret


; input: rax as pointer to string (i.g. mov rax, stringLabel)
; output: print string at rax
_print:
	push rax ; rax is storing the address of the string, and we'll
		 ; store this address on the stack 
	mov rbx, 0 ; rbx will count the length of the string

	; this label "_print" doesn't have a "ret", so the code
	; will run down nonstop!
_printLoop:
	inc rax ; rax is being used to store each char of the string.
	inc rbx
	mov cl, [rax] ; "cl" has the 8 least significant bits of rcx
	cmp cl, 0
	jne _printLoop

	; we used to print a string like this:
	; mov rax, 1
	; mov rdi, 1
	; mov rsi, [label of the string]
	; mov rdx, [length of the string]
	; syscall

	mov rax, SYS_WRITE
	mov rdi, STDOUT
	pop rsi ; we've pushed the address to the stack, and now
		; we're popping it to rsi
	mov rdx, rbx
	syscall 

	ret



; just like return 0; from C
_return0:
	mov rax, 60
	mov rdi, 0
	syscall ;sys_exit <-> return 0;

