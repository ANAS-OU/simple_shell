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
char **str_split(char *str, char *by);
unsigned int substr_counter(char *str, char *by);
char *get_path(char *cmd);
int execute_cmd(char *input, char *pgm);
void free_list(char **list);
void print_error(char *pgm, char *cmd);

/* _strlen.c */
int _strlen(char *str);

/* _getline.c */
ssize_t _getline(char **lineptr, size_t *bsize, FILE *stream);
int _fgetc(FILE *stream);

/**********************
 *   The Environment
 **********************/
extern char **environ;

#endif /* SHELL_H */
