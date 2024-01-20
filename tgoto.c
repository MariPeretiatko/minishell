#include <curses.h>
#include <term.h>
#include <stdio.h>

int main() {
    // setupterm(NULL, STDOUT_FILENO, NULL);

    // Получить строку для перемещения к указанным координатам
    char *move_to = tgoto(tgetstr("cm", NULL), 10, 5);

    if (move_to != NULL) {
        printf("Управляющая последовательность для перемещения: %s\n", move_to);
    } else {
        printf("Не удалось создать управляющую последовательность для перемещения.\n");
    }

    return 0;
}
