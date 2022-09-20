global _start

_start:
    push byte 'H'
    push byte 'i'
    push byte '!'

    mov rax, 4
    mov rbx, 1
    mov rcx, rsp
    mov rdx, 4
    syscall

    mov rax, 60
    mov rdi, 0
    syscall