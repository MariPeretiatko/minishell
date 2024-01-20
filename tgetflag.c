// int tgetflag(const char *id);
// id: идентификатор флага, который вы хотите извлечь.
// Возвращаемое значение:

// Если флаг успешно найден и его значение установлено в "true", то tgetflag возвращает 1.
// Если флаг не найден или его значение установлено в "false", то возвращается 0.
// Пример использования tgetflag:
#include <curses.h>
#include <stdio.h>

int main() {
    // Извлечение флага auto_left_margin
    int flag_value = tigetflag("auto_left_margin");

    if (flag_value == 1) {
        printf("Флаг auto_left_margin установлен в true.\n");
    } else if (flag_value == 0) {
        printf("Флаг auto_left_margin установлен в false или не найден.\n");
    } else {
        perror("Ошибка при извлечении флага");
        return 1;
    }

    return 0;
}
