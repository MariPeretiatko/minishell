#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


//gcc your_program.c -o your_program -lreadline -L/usr/include -lncurses

int main() {
    char *input;

    // Инициализация библиотеки readline
    rl_bind_key('\t', rl_complete);

    // Чтение строки с поддержкой истории
    input = readline("Введите строку: ");

    // Проверка наличия введенной строки
    if (input == NULL) {
        fprintf(stderr, "Ошибка при чтении строки\n");
        return 1;
    }

    // Вывод введенной строки
    printf("Вы ввели: %s\n", input);

    // Добавление строки в историю
    add_history(input);

    // Освобождение памяти, выделенной readline
    free(input);

    return 0;
}