#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


// oldfd: исходный файловый дескриптор, который нужно продублировать.
// Возвращаемое значение:

// В случае успеха, dup возвращает новый файловый дескриптор.
// В случае ошибки, возвращается -1, и переменная errno устанавливается соответствующим образом.
// Функция dup создает новый файловый дескриптор, который указывает на тот же самый открытый файл, что и исходный дескриптор oldfd. Новый файловый дескриптор является самым минимальным доступным, еще неиспользуемым файловым дескриптором.
int main() {
    const char *filename = "/Users/mperetia/projects/minishell/dup.c"; // Замените на реальный путь к файлу

    // Открытие файла
    int file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    // Создание дубликата файла с использованием dup
    int dup_descriptor = dup(file_descriptor);
    if (dup_descriptor == -1) {
        perror("Ошибка при создании дубликата файла");
        close(file_descriptor);
        return 1;
    }

    // Чтение из оригинального файла
    char buffer[1024];
    ssize_t bytesRead = read(file_descriptor, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("Ошибка при чтении из оригинального файла");
        close(file_descriptor);
        close(dup_descriptor);
        return 1;
    }

    // Вывод содержимого из дубликата
    write(STDOUT_FILENO, buffer, bytesRead);

    // Закрытие файловых дескрипторов
    close(file_descriptor);
    close(dup_descriptor);

    return 0;
}
