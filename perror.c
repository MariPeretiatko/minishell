#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// s: Строка, которая будет выведена перед текстовым описанием ошибки. Может быть NULL.
// В простейшем случае, если функция завершается с ошибкой (и устанавливает переменную errno), perror используется для автоматического вывода сообщения об ошибке:

int main() {
    FILE *file = fopen("/Users/mperetia/projects/minishell/test.c", "r");

    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return EXIT_FAILURE;
    }

    // код для работы с файлом

    fclose(file);

    return EXIT_SUCCESS;
}
