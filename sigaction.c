#include <signal.h>

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
// signum: номер сигнала, для которого нужно установить обработчик.
// act: указатель на структуру struct sigaction, описывающую новый обработчик сигнала и опции.
// oldact: указатель на структуру struct sigaction, в которой будет сохранен предыдущий обработчик сигнала.
// struct sigaction {
//     void (*sa_handler)(int);             // Указатель на функцию-обработчик
//     sigset_t sa_mask;                    // Маска сигналов, которые блокируются во время выполнения обработчика
//     int sa_flags;                        // Флаги, управляющие поведением обработчика
//     void (*sa_sigaction)(int, siginfo_t *, void *);  // Указатель на функцию-обработчик с дополнительной информацией
// };


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Обработчик сигнала
void signal_handler(int signum) {
    printf("Получен сигнал %d.\n", signum);
}

int main() {
    struct sigaction sa;

    // Инициализация структуры sigaction
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;

    // Установка обработчика для сигнала SIGINT (Ctrl+C)
    if (sigaction(SIGINT, &sa, NULL) == -1) {
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
