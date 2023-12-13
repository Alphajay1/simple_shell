#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

extern char **environ;

size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);

void display_prompt(void);
void exec_cmd(char *command);
pid_t check_fork(void);
size_t _strcspn(const char *s, const char *reject);
int _putchar(char c);
void _puts(char *s);

#endif
