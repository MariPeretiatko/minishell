#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h> 
# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<signal.h>
# include	<dirent.h>
# include	<fcntl.h>
////gcc rl_replace_line.c -o your_program -lreadline -lncurses
int main() {
    char *prompt = "Введите что-то: ";
    char *input;

    // Инициализация библиотеки readline
    rl_bind_key('\t', rl_complete);

    // Основной цикл ввода
    while ((input = readline(prompt)) != NULL) {
        // Обработка введенной строки (здесь может быть ваша логика)

        // Замена текущей строки
        rl_replace_line("Новая строка", 0);

        // Принудительное обновление отображения
        rl_forced_update_display();

        // Освобождение памяти, выделенной readline
        free(input);
    }

    return 0;
}
