#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

extern char **environ;

void display_prompt(void);
void exec_cmd(char *command);
pid_t check_fork(void);
void search_path(char *args[]);
int env_cmd(char **args);
void env_print(void);
#endif
