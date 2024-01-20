// int tcgetattr(int fd, struct termios *termios_p);
// fd: файловый дескриптор терминала.
// termios_p: указатель на структуру termios, в которую будут записаны текущие атрибуты терминала.
// Возвращаемое значение:

// В случае успеха, tcgetattr возвращает 0.
// В случае ошибки, возвращается -1, и переменная errno устанавливается соответствующим образом.

// #include <stdio.h>
// #include <termios.h>
// #include <unistd.h>

// int main() {
//     struct termios term_attr;

//     // Получение текущих атрибутов терминала
//     if (tcgetattr(STDIN_FILENO, &term_attr) != 0) {
//         perror("Ошибка при получении атрибутов терминала");
//         return 1;
//     }

//     // Вывод текущих атрибутов
//     printf("Скорость передачи данных: %lu bps\n", cfgetispeed(&term_attr));
//     printf("Режимы ввода/вывода: %lx\n", term_attr.c_iflag);
//     printf("Контроль построчного ввода: %lx\n", term_attr.c_lflag);
//     // Другие атрибуты терминала можно вывести по аналогии

//     return 0;
// }
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void print_termios_attributes(const struct termios *term_attr) {
    printf("Скорость передачи данных (input): %lu bps\n", cfgetispeed(term_attr));
    printf("Скорость передачи данных (output): %lu bps\n", cfgetospeed(term_attr));

    printf("Режимы ввода: %lx\n", term_attr->c_iflag);
    printf("Режимы вывода: %lx\n", term_attr->c_oflag);
    printf("Режимы управления (control): %lx\n", term_attr->c_cflag);
    printf("Режимы локальные: %lx\n", term_attr->c_lflag);

    printf("Количество байтов в очереди на ввод: %d\n", term_attr->c_cc[VMIN]);
    printf("Таймаут ожидания ввода (в десятых секунды): %d\n", term_attr->c_cc[VTIME]);
}

int main() {
    struct termios term_attr;

    // Получение текущих атрибутов терминала
    if (tcgetattr(STDIN_FILENO, &term_attr) != 0) {
        perror("Ошибка при получении атрибутов терминала");
        return 1;
    }

    // Вывод текущих атрибутов
    print_termios_attributes(&term_attr);

    return 0;
}
