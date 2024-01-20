#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h> 

int main() {
    char *prompt = "minishell> ";
    char *input;

    // // Инициализация библиотеки readline
    // rl_bind_key('\t', rl_complete);

    // Основной цикл ввода
    while ((input = readline(prompt)) != NULL) {
        // Обработка введенной строки (здесь может быть ваша логика)

        // Принудительное обновление отображения
        rl_redisplay();
		add_history(input);

        // Освобождение памяти, выделенной readline
        free(input);
    }

    return 0;
}