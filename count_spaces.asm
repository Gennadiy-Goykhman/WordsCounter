section .text
global count_spaces
count_spaces:
    xor rax, rax            ; Обнуляем счетчик
    jmp check_space

count_next_char:
    inc rcx                 ; Переходим к следующему символу в строке
check_space:
    movzx r8, byte [rcx]      ; Загружаем символ из памяти
    cmp r8, 0               ; Проверяем конец строки
    je end_counting

    cmp r8, 32              ; Сравниваем символ с пробелом (ASCII код 32)
    je increment_counter

    jmp count_next_char

increment_counter:
    inc rax                 ; Увеличиваем счетчик пробелов
    jmp count_next_char

end_counting:
    ret