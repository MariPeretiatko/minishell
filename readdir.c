// struct dirent *readdir(DIR *dirp);
// dirp: указатель на структуру DIR, представляющую открытый каталог.
// Возвращаемое значение:

// В случае успеха, readdir возвращает указатель на структуру dirent.
// В конце каталога или при ошибке, возвращается NULL, и переменная errno устанавливается соответствующим образом.
// struct dirent {
//     ino_t d_ino;         /* inode number */
//     off_t d_off;         /* offset to the next dirent */
//     unsigned short d_reclen; /* length of this record */
//     unsigned char d_type;    /* type of file; not supported by all file system types */
//     char d_name[];       /* filename */
// };
#include <stdio.h>
#include <dirent.h>

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
