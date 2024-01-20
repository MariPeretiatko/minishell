#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *filename = "/Users/mperetia/projects/minishell/fork.c"; // Замените на реальный путь к символической ссылке

    struct stat link_info;

    // Получение информации о символической ссылке
    if (lstat(filename, &link_info) == -1) {
        perror("Ошибка при получении информации о символической ссылке");
        return 1;
    }

    // Вывод информации о символической ссылке
    printf("Информация о символической ссылке %s:\n", filename);
    printf("Размер: %lld байт\n", link_info.st_size);
    printf("Идентификатор пользователя-владельца: %d\n", link_info.st_uid);
    printf("Идентификатор группы-владельца: %d\n", link_info.st_gid);
    printf("Режим доступа: %o\n", link_info.st_mode);

    return 0;
}
