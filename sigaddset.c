#include <stdio.h>
#include <signal.h>

int main() {
    sigset_t signal_set;

    // Инициализация пустого набора сигналов
    if (sigemptyset(&signal_set) == -1) {
        perror("Ошибка при инициализации пустого набора сигналов");
        return 1;
    }

    // Добавление сигнала SIGINT в набор
    if (sigaddset(&signal_set, SIGINT) == -1) {
        perror("Ошибка при добавлении сигнала в набор");
        return 1;
    }

    printf("Сигнал SIGINT добавлен в набор сигналов.\n");

    // Теперь вы можете использовать signal_set в функциях, таких как sigprocmask, чтобы управлять блокировкой сигналов.

    return 0;
}
