#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>
// #include <malloc.h>

//gcc rl_on_new_line.c -o your_program -lreadline -lncurses
int main() {
    char *prompt = "Введите что-то: ";
    char *input;

    // Инициализация библиотеки readline
    rl_bind_key('\t', rl_complete);

    // Основной цикл ввода
    while ((input = readline(prompt)) != NULL) {
        // Обработка введенной строки (здесь может быть ваша логика)

        // Освобождение памяти, выделенной readline
		if(!strcmp(input, "exit"))
		{
			free(input);
			break;
		}
        free(input);

        // Перемещение курсора на новую строку
        rl_on_new_line();
        // Принудительное обновление отображения
        rl_forced_update_display();
		write(1, "\n", 1);
    }

    return 0;
}
