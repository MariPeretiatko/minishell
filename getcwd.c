#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {
    // Получение размера буфера, необходимого для хранения текущего рабочего каталога
    long size = pathconf(".", _PC_PATH_MAX); //pathconf ?
    if ((size == -1) && (errno == 0)) {
        size = 1024;  // Значение по умолчанию, если невозможно определить максимальный размер
    }

    // Выделение буфера
    char *buf = (char *)malloc((size_t)size);
    if (buf == NULL) {
        perror("Ошибка при выделении памяти");
        return 1;
    }

    // Получение текущего рабочего каталога
    if (getcwd(buf, (size_t)size) == NULL) {
        perror("Ошибка при получении текущего рабочего каталога");
        free(buf);
        return 1;
    }

    // Вывод текущего рабочего каталога
    printf("Текущий рабочий каталог: %s\n", buf);

    // Освобождение выделенной памяти
    free(buf);

    return 0;
}
