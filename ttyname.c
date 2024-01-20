// char *ttyname(int fd);
// fd: файловый дескриптор, для которого нужно получить имя терминала.
// Возвращаемое значение:

// Если файловый дескриптор fd ассоциирован с терминалом, то ttyname возвращает указатель на строку, содержащую имя терминала.
// Если файловый дескриптор fd не является терминалом, то возвращается NULL.
// В случае ошибки, возвращается NULL, и переменная errno устанавливается соответствующим образом.
// Пример использования ttyname
#include <stdio.h>
#include <unistd.h>

int main() {
    int stdin_fd = STDIN_FILENO;
    int stdout_fd = STDOUT_FILENO;
    int stderr_fd = STDERR_FILENO;

    char *ttyname_stdin = ttyname(stdin_fd);
    char *ttyname_stdout = ttyname(stdout_fd);
    char *ttyname_stderr = ttyname(stderr_fd);

    if (ttyname_stdin != NULL) {
        printf("Стандартный ввод (stdin) ассоциирован с терминалом: %s\n", ttyname_stdin);
    } else {
        printf("Стандартный ввод (stdin) не ассоциирован с терминалом.\n");
    }

    if (ttyname_stdout != NULL) {
        printf("Стандартный вывод (stdout) ассоциирован с терминалом: %s\n", ttyname_stdout);
    } else {
        printf("Стандартный вывод (stdout) не ассоциирован с терминалом.\n");
    }

    if (ttyname_stderr != NULL) {
        printf("Стандартный вывод ошибок (stderr) ассоциирован с терминалом: %s\n", ttyname_stderr);
    } else {
        printf("Стандартный вывод ошибок (stderr) не ассоциирован с терминалом.\n");
    }

    return 0;
}
