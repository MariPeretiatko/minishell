#include <stdio.h>
#include <signal.h>

int main() {
    sigset_t signal_set;

    // Инициализация пустого набора сигналов
    if (sigemptyset(&signal_set) == -1) {
        perror("Ошибка при инициализации пустого набора сигналов");
        return 1;
    }

    printf("Набор сигналов инициализирован успешно.\n");

    // Далее можно добавлять или удалять сигналы из этого набора

    return 0;
}
