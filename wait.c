// pid_t wait(int *status);

// status: указатель на переменную, в которой будет сохранен статус завершения дочернего процесса.
// Возвращаемое значение:

// В случае успеха, wait возвращает идентификатор (PID) завершившегося дочернего процесса.
// В случае ошибки, возвращается -1.
// Пример использования fork и wait:
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    printf("Это родительский процесс (PID=%d).\n", getpid());

    // Создание нового процесса
    child_pid = fork();

    if (child_pid == -1) {
        perror("Ошибка при вызове fork");
        return 1;
    }

    if (child_pid == 0) {
        // Код, выполняемый в дочернем процессе
        printf("Это дочерний процесс (PID=%d).\n", getpid());
        sleep(2);
        printf("Дочерний процесс завершен.\n");
    } else {
        // Код, выполняемый в родительском процессе
        printf("Дочерний процесс создан с PID=%d.\n", child_pid);

        // Ожидание завершения дочернего процесса
        int status;
        pid_t terminated_pid = wait(&status);

        if (terminated_pid == -1) {
            perror("Ошибка при вызове wait");
            return 1;
        }

        printf("Дочерний процесс с PID=%d завершился с кодом возврата %d.\n", terminated_pid, status);
    }

    return 0;
}
