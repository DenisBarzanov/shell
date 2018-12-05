//
// Created by denisbarzanov2002 on 12/5/18.
//

#ifndef OS_SHELL_1_DSH_BUILTINS_H
#define OS_SHELL_1_DSH_BUILTINS_H

int dsh_cd(char **args);
int dsh_help(char **args);
int dsh_exit(char **args);
typedef int built_in_func_t(char **);

/*
 * Function Declarations for builtin shell commands:
 */
extern char *builtin_str[];
extern built_in_func_t (*builtin_func[]);

int dsh_num_builtins();

#endif //OS_SHELL_1_DSH_BUILTINS_H
