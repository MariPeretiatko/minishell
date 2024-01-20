#include <stdio.h>
#include <dirent.h>


// DIR *opendir(const char *dirname);
// dirname: строка, содержащая путь к каталогу, который нужно открыть.
// Возвращаемое значение:

// В случае успеха, opendir возвращает указатель на структуру DIR.
// В случае ошибки, возвращается NULL, и переменная errno устанавливается соответствующим образом.
int main() {
    const char *directory_path = "/Users/mperetia/projects"; // Замените на реальный путь к каталогу

    // Открытие каталога
    DIR *directory = opendir(directory_path);

    if (directory == NULL) {
        perror("Ошибка при открытии каталога");
        return 1;
    }

    // Чтение файлов из каталога
    struct dirent *entry;

    while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Закрытие каталога
    closedir(directory);

    return 0;
}
