#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *prompt = "Введите что-то: ";
    char *input;

    // Инициализация библиотеки readline
    rl_bind_key('\t', rl_complete);

    // Основной цикл ввода
    while ((input = readline(prompt)) != NULL) {
        // Обработка введенной строки (здесь может быть ваша логика)

        // Принудительное обновление отображения
        rl_redisplay();

        // Добавление введенной строки в историю
        add_history(input);

        // Освобождение памяти, выделенной readline
        free(input);
    }

    return 0;
}
