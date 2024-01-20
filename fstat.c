// int fstat(int fd, struct stat *buf);
// fd: файловый дескриптор файла, для которого нужно получить информацию.
// buf: указатель на структуру struct stat, в которую будет записана информация о файле.
// Возвращаемое значение:

// В случае успеха, fstat возвращает 0.
// В случае ошибки, возвращается -1, и переменная errno устанавливается соответствующим образом.
// Пример использования fstat:

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *filename = "/Users/mperetia/projects/minishell/stat.c"; // Замените на реальный путь к файлу

    // Открытие файла
    int file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    // Получение информации о файле с использованием fstat
    struct stat file_info;

    if (fstat(file_descriptor, &file_info) == -1) {
        perror("Ошибка при получении информации о файле");
        close(file_descriptor); // Закрытие файла
        return 1;
    }

    // Вывод информации о файле
    printf("Информация о файле %s:\n", filename);
    printf("Размер: %lld байт\n", file_info.st_size);
    printf("Идентификатор пользователя-владельца: %d\n", file_info.st_uid);
    printf("Идентификатор группы-владельца: %d\n", file_info.st_gid);
    printf("Режим доступа: %o\n", file_info.st_mode);

    // Закрытие файла
    close(file_descriptor);

    return 0;
}
