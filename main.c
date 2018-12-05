#include <wait.h>
#include <stdbool.h>
#include "apue.h"
#include "dsh_builtins.h"

#define LSH_TOK_BUFSIZE 64

#define TOK_DELIM " \t\r\n\a"

int dsh_launch(char **args);
int dsh_execute(char **args);
static char ** parse_cmdline(const char *cmdline);

int
main(int argc, char **argv) {
    char line[MAXLINE];
    char **args;
    int stop;
    bool eof;
    signal(SIGHUP, SIG_IGN); // for ide purposes only
    signal(SIGCONT, SIG_IGN);
    do {
        printf("$ ");
        eof = !fgets(line, MAXLINE, stdin);
        args = parse_cmdline(line);
        if (eof) {
            /*
             * We read EOF (someone maybe pressed Ctrl+D)
             * $ Ctrl+D
             * We must add a newline and exit
             */
            printf("\n");
            stop = true;
        } else {
            stop = dsh_execute(args);
        }
        free(args);
    } while (!stop);
    /**
     * @var stop is introduced so as to
     * free the args after we want to exit
     * If we didn't do that when we exit we wouldn't
     * reach the free(args) and would create a potential
     * memory leak.
     */
}

char **
parse_cmdline(const char *cmdline) {
    char *line = strdup(cmdline);
    int bufsize = LSH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (tokens == NULL) {
        err_sys("alloc error");
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL) {
        tokens[position++] = token;

        if (position >= bufsize) {
            bufsize += LSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                err_sys("alloc error");
            }
        }

        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

int
dsh_launch(char **args) {
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        err_ret("dsh");
        return 0;
    } else if (pid == 0) {
        if (execvp(args[0], args) < 0) {
            err_sys("dsh");
            /*
             * We already have a new process
             * so exit to make it a zombie
             */
        }
        exit(EXIT_FAILURE); // shouldn't get here
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 0;
}

int
dsh_execute(char **args) {
    int i;

    if (args[0] == NULL) {
        // An empty command was entered.
        return 0;
    }

    for (i = 0; i < dsh_num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

    return dsh_launch(args);
}

