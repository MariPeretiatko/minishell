#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// int main() {
//     pid_t my_pid = getpid();

//     // Отправка сигнала SIGTERM текущему процессу
//     if (kill(my_pid, SIGTERM) == -1) {
//         perror("Ошибка при отправке сигнала");
//         return 1;
//     }

//     printf("Сигнал SIGTERM отправлен успешно.\n");

//     return 0;
// }
#include <stdio.h>
#include <signal.h>

int main() {
    pid_t target_pid = 1234;  // Замените на реальный идентификатор целевого процесса

    // Отправка сигнала SIGUSR1 целевому процессу
    if (kill(target_pid, SIGUSR1) == -1) {
        perror("Ошибка при отправке сигнала");
        return 1;
    }

    printf("Сигнал SIGUSR1 отправлен успешно.\n");

    return 0;
}
