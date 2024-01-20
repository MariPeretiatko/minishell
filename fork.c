#include <stdio.h>
#include <unistd.h>

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
    } else {
        // Код, выполняемый в родительском процессе
        printf("Дочерний процесс создан с PID=%d.\n", child_pid);
    }

    return 0;
}
