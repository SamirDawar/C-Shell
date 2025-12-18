#ifndef SHELL_H 
#define SHELL_H 

#include <stdio.h>
#include <stdlib.h>



//function signatures
void lsh_loop(void);
char *lsh_read_line(void);
void lsh_split_line(char *line);
int lsh_execute(char *args);

#endif
