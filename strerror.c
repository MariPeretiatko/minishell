// char *strerror(int errnum);
// errnum: код ошибки (например, значение переменной errno).
// Возвращаемое значение:

// Указатель на строку с текстовым описанием ошибки.
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    FILE *file = fopen("/nonexistent/file", "r");

    if (file == NULL) {
        // Ошибка открытия файла
        perror("Ошибка при открытии файла");

        // Получение текстового описания ошибки с использованием strerror
        fprintf(stderr, "Ошибка: %s\n", strerror(errno));
    }

    return 0;
}
