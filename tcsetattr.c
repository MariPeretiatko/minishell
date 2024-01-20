// int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
// fd: файловый дескриптор терминала.
// optional_actions: действие, определяющее, когда изменения должны вступить в силу. Может быть одним из следующих значений:
// TCSANOW: изменения применяются немедленно.
// TCSADRAIN: изменения применяются после завершения вывода.
// TCSAFLUSH: изменения применяются после завершения вывода и сброса ввода.
// termios_p: указатель на структуру termios, содержащую новые атрибуты терминала.
// Возвращаемое значение:

// В случае успеха, tcsetattr возвращает 0.
// В случае ошибки, возвращается -1, и переменная errno устанавливается соответствующим образом.a
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios new_attr, old_attr;

    // Получение текущих атрибутов терминала
    if (tcgetattr(STDIN_FILENO, &old_attr) != 0) {
        perror("Ошибка при получении атрибутов терминала");
        return 1;
    }

    // Копирование текущих атрибутов для редактирования
    new_attr = old_attr;

    // Пример изменения атрибутов (например, выключение ECHO)
    new_attr.c_lflag &= ~ECHO;

    // Применение новых атрибутов терминала
    if (tcsetattr(STDIN_FILENO, TCSANOW, &new_attr) != 0) {
        perror("Ошибка при установке новых атрибутов терминала");
        return 1;
    }

    printf("Введите текст (ECHO выключено): ");
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    printf("Вы ввели: %s", buffer);

    // Восстановление предыдущих атрибутов терминала
    if (tcsetattr(STDIN_FILENO, TCSANOW, &old_attr) != 0) {
        perror("Ошибка при восстановлении атрибутов терминала");
        return 1;
    }

    return 0;
}
