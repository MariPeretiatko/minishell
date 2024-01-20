#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <curses.h>

// int tputs(const char *str, int affcnt, int (*putc_func)(int));

int main() {

    // Получить строку для очистки экрана
    char *clear_screen = tgetstr("clear", NULL);

    if (clear_screen != NULL) {
        // Использовать tputs для вывода строки
        if (tputs(clear_screen, 1, putchar) == ERR) {
            printf("Ошибка при выводе управляющей последовательности.\n");
            return 1;
        }

        printf("Экран очищен!\n");
    } else {
        printf("Строка для очистки экрана не найдена.\n");
    }

    return 0;
}
