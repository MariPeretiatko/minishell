#include <stdio.h>
#include <unistd.h>

int main() {
    const char *new_directory = "/Users/mperetia/projects"; // Замените на реальный путь

    // Попытка изменения текущего рабочего каталога
    if (chdir(new_directory) == -1) {
        perror("Ошибка при изменении текущего рабочего каталога");
        return 1;
    }

    // Теперь текущим рабочим каталогом будет new_directory

    printf("Текущий рабочий каталог изменен на: %s\n", new_directory);

    return 0;
}
