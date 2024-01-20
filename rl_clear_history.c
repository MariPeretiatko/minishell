#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


//gcc rl_clear_history.c -o your_program -lreadline -lncurses
int main() {
    // Добавление нескольких строк в историю
    add_history("command1");
    add_history("command2");
    add_history("command3");

    // Вывод текущего состояния истории
    printf("История перед очисткой:\n");
    for (int i = 1; i <= history_length; i++) {
        printf("%d: %s\n", i, history_get(i)->line);
    }

    // Очистка истории
    clear_history();

    // Вывод состояния истории после очистки
    printf("\nИстория после очистки:\n");
    for (int i = 1; i <= history_length; i++) {
        printf("%d: %s\n", i, history_get(i)->line);
    }

    return 0;
}
// #include <stdio.h>
// #include <readline/readline.h>
// #include <readline/history.h>

// int main() {
//     // Добавление нескольких строк в историю
//     add_history("command1");
//     add_history("command2");
//     add_history("command3");

//     // Вывод текущего состояния истории
//     printf("История перед очисткой:\n");
//     for (int i = 1; i <= history_length; i++) {
//         printf("%d: %s\n", i, history_get(i)->line);
//     }

//     // Очистка истории (если rl_clear_history() существует)
//     #ifdef rl_clear_history
//     rl_clear_history();
//     #else
//     fprintf(stderr, "Функция rl_clear_history() не поддерживается на данной версии библиотеки readline.\n");
//     #endif

//     // Вывод состояния истории после очистки
//     printf("\nИстория после очистки:\n");
//     for (int i = 1; i <= history_length; i++) {
//         printf("%d: %s\n", i, history_get(i)->line);
//     }

//     return 0;
// }