#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *filename = "/path/to/file"; // Замените на реальный путь к файлу

    // Открытие файла
    int file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    // Создание дубликата файла с использованием dup2
    int dup_descriptor = dup2(file_descriptor, 10); // 10 - пример нового номера дескриптора
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
