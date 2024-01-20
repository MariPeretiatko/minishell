// struct stat {
//     dev_t         st_dev;      // ID устройства
//     ino_t         st_ino;      // Номер индексного узла (inode)
//     mode_t        st_mode;     // Режим доступа
//     nlink_t       st_nlink;    // Количество жестких ссылок
//     uid_t         st_uid;      // Идентификатор пользователя-владельца
//     gid_t         st_gid;      // Идентификатор группы-владельца
//     off_t         st_size;     // Размер в байтах
//     time_t        st_atime;    // Время последнего доступа
//     time_t        st_mtime;    // Время последнего изменения
//     time_t        st_ctime;    // Время последнего изменения inode
//     blksize_t     st_blksize;  // Размер блока ввода-вывода файловой системы
//     blkcnt_t      st_blocks;   // Количество выделенных блоков
// };

// int stat(const char *path, struct stat *buf);
// path: строка, содержащая путь к файлу или каталогу, о котором нужно получить информацию.
// buf: указатель на структуру struct stat, в которую будет записана информация о файле.
// Возвращаемое значение:

// В случае успеха, stat возвращает 0.
// В случае ошибки, возвращается -1, и переменная errno устанавливается соответствующим образом.
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *filename = "/Users/mperetia/projects/minishell/fork.c"; // Замените на реальный путь к файлу

    struct stat file_info;

    // Получение информации о файле
    if (stat(filename, &file_info) == -1) {
        perror("Ошибка при получении информации о файле");
        return 1;
    }

    // Вывод информации о файле
    printf("Информация о файле %s:\n", filename);
    printf("Размер: %lld байт\n", file_info.st_size);
    printf("Идентификатор пользователя-владельца: %d\n", file_info.st_uid);
    printf("Идентификатор группы-владельца: %d\n", file_info.st_gid);
    printf("Режим доступа: %o\n", file_info.st_mode);

    return 0;
}
