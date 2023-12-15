section .text
global count_words
count_words:
    xor rax, rax            ; Обнуляем счетчик
    xor r10, r10
    jmp check_space

count_next_char:
    add r10, 1
    inc rcx                 ; Переходим к следующему символу в строке
check_space:
    movzx r8, byte [rcx]      ; Загружаем символ из памяти
    cmp r8, 0               ; Проверяем конец строки
    je end_counting

    cmp r8, 32              ; Сравниваем символ с пробелом (ASCII код 32)
    je increment_counter

    jmp count_next_char

increment_counter:
    mov qword [rdx], r10
    inc rdx
    xor r10, r10                 ; Увеличиваем счетчик пробелов
    inc rcx
    jmp check_space

end_counting:
    mov qword [rdx], r10
    mov rax, rdx
    ret