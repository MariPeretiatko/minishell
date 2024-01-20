// int tgetent(char *bp, const char *name);
// bp: буфер, в который будут загружены данные о возможностях терминала.
// name: имя терминала (например, "xterm", "vt100"), для которого нужно загрузить данные.
// Возвращаемое значение:

// Если данные о терминале успешно загружены, то tgetent возвращает 1.
// Если не удается найти файл terminfo, то возвращается 0.
// В случае ошибки, возвращается -1.
#include <curses.h>
#include <stdio.h>
#include <term.h>

int main() {
    char term_buffer[1024];

    // Загрузка данных о возможностях терминала "xterm"
    int result = tgetent(term_buffer, "xterm");

    if (result == 1) {
        printf("Данные о терминале успешно загружены:\n%s\n", term_buffer);
    } else if (result == 0) {
        printf("Файл terminfo для терминала не найден.\n");
    } else {
        perror("Ошибка при загрузке данных о терминале");
        return 1;
    }

    return 0;
}
