#ifndef SHELL_H 
#define SHELL_H 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void lsh_loop(void);
char *lsh_read_line(void);
char **lsh_split_line(char *line);
char lsh_launch(char **args);

//shell function
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

#endif
