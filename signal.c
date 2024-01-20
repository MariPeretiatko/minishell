#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Обработчик сигнала
void signal_handler(int signum) {
    printf("Получен сигнал %d.\n", signum);
}

int main() {
    // Установка обработчика для сигнала SIGINT (Ctrl+C)
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        perror("Ошибка при установке обработчика для SIGINT");
        return 1;
    }

    printf("Ожидание сигнала SIGINT...\n");

    // Бесконечный цикл
    while (1) {
        sleep(1);
    }

    return 0;
}
