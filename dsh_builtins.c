//
// Created by denisbarzanov2002 on 12/5/18.
//
#include "apue.h"
#include "dsh_builtins.h"

#define STREQ(a,b) (strcmp((a),(b))==0)

built_in_func_t (*builtin_func[]) = {
        &dsh_cd,
        &dsh_help,
        &dsh_exit
};

char *builtin_str[] = {
        "cd",
        "help",
        "exit"
};

int dsh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
int
dsh_cd(char **args) {
    if (args[1] == NULL || STREQ(args[1], "~")) {
        /*
         * If no arguments to cd or ~ then home directory
         */
        if (chdir(getenv("HOME")) != 0) {
            err_ret("dsh");
            return 0;
        }
        //err_msg("dsh: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            err_ret("dsh");
            return 0;
        }
    }
    return 0;
}

int
dsh_help(char **args) {
    int i;
    printf("Denis Barzanov's DSH\n"
           "Type program names and arguments, and hit enter.\n"
           "The following are built in:\n");

    for (i = 0; i < dsh_num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 0;
}

int dsh_exit(char **args) {
    return 1;
}