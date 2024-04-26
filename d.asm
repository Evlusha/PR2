section .data
   numbers dd 5, 123, 12
   size dd 3
   resultStr db '0', 10  ; Массив для хранения результата как строки, 10 - перевод строки
   resultLen equ 1       ; Длина строки результата
 
section .bss
 
section .text
   global _start
 
_start:
   mov rsi, numbers    ; Адрес первого элемента массива
   mov rcx, [size]     ; Размер массива
   xor rbx, rbx        ; Счетчик простых чисел
 
.loop:
   mov eax, [rsi]      ; Загружаем значение из массива
   call isProst        ; Проверяем на простоту
   test al, al         ; Проверяем результат
   jz .continue        ; Если не простое, переходим к следующему числу
   inc rbx             ; Увеличиваем счетчик простых чисел
 
.continue:
   add rsi, 4          ; Переходим к следующему элементу массива
   loop .loop          ; Повторяем цикл для всего массива
   dec rbx
   ; Преобразование числа в строку
   add rbx, '0'        ; Преобразуем число в символ
   mov [resultStr], rbx ; Сохраняем символ в строке
 
   ; Вывод результата
   mov rsi, resultStr  ; Адрес строки результата
   mov rdx, resultLen  ; Длина строки результата
   mov rax, 1          ; Системный вызов sys_write
   mov rdi, 1          ; Файловый дескриптор stdout
   syscall
 
   ; Выход из программы
   mov eax, 60         ; Системный вызов sys_exit
   xor edi, edi        ; Код возврата
   syscall
 
isProst:
   cmp eax, 1          ; Проверяем, больше ли число 1
   jle .not_prime      ; Если нет, то оно точно не простое
   mov ecx, 2          ; Первый делитель
 
.check_loop:
   cmp ecx, eax        ; Если делитель равен числу, то число простое
   je .prime
   mov edx, 0          ; Обнуляем edx перед делением
   div ecx             ; Делим eax на ecx
   test edx, edx       ; Проверяем остаток
   jz .not_prime       ; Если остаток 0, число не простое
   inc ecx             ; Увеличиваем делитель
   cmp ecx, eax
   jle .check_loop      ; Повторяем, если делитель меньше числа
 
.prime:
   mov al, 1           ; Возвращаем 1, если число простое
   ret
 
.not_prime:
   xor al, al          ; Возвращаем 0, если число не простое
   ret