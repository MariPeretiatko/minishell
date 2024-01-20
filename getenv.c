// char *getenv(const char *name);

// ``
// name: указатель на строку, содержащую имя переменной окружения.
// В

// Еслиgetenvсоответственно
// Если переменная с указанным именем отсутствует, возвращается NULL.
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Пример: получение значения переменной окружения "HOME"
    char *home_path = getenv("HOME");

    if (home_path != NULL) {
        printf("Значение переменной окружения HOME: %s\n", home_path);
    } else {
        printf("Переменная окружения HOME не определена.\n");
    }

    return 0;
}
