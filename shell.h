#ifndef SHELL_H
#define SHELL_H

/********************
 * Standard Libraries
 ********************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**********************
 * Defined Constantes
 **********************/
#define BUFSIZE 1024
#define LINESIZE 120

/**********************
 * Functions prototype
 **********************/
/* str_split.c */
char **str_split(char *str, char *by);
unsigned int token_count(char *str, char *by);

/* execute_cmd.c */
int execute_cmd(char *input, char *pgm);
char *get_path(char *cmd);
int customize_env(char **inList);

/* _string.c */
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/* free_list.c */
void free_list(char **list);

/* print_error.c */
void print_error(char *pgm, char *cmd);

/**********************
 *   The Environment
 **********************/
extern char **environ;

#endif /* SHELL_H */
