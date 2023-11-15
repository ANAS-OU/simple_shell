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
/* token_count.c */
unsigned int token_count(char *str, char *by);
/* get_path.c */
char *get_path(char *cmd);
/* execute_cmd.c */
int execute_cmd(char *input, char *pgm);
/* free_list.c */
void free_list(char **list);
/* print_error.c */
void print_error(char *pgm, char *cmd);
/* _strlen.c */
int _strlen(char *str);

/**********************
 *   The Environment
 **********************/
extern char **environ;

#endif /* SHELL_H */
