section .text
global test
test:
    mov qword [rdx], 20
    mov rax, rdx
    ret