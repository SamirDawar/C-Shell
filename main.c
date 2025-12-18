#include "shell.h"

int main(int argc, char **argv){

  
  lsh_loop();

  return EXIT_SUCCESS;
}


void lsh_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    printf("lshell> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);



    free(line);
    free(args);

  } while(status);
}


// read user inpum t
#define LSH_RL_BUFSIZE 1024
char *lsh_read_line(void) {
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(buffer * sizeof(char));
  int c;

  if(!buffer) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }
  
  while(1) {
    //read character
    c = getchar();
    
    //chech if we hit EOF, replace it with a null char and return.
    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer; 
    } else {
      buffer[position] = c;
    }
    position++;
    
    //if we have exceeded the buffer, reallocate
    if (position >= buffsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, buffsize);

      if (!bufsize) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}


#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
char **lsh_split_line(char *line) {
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(*char));
  char token;
  
  if (!tokens) {
    fprintf(stderr, "Error Allocating memory for tokenization");
    exit(EXIT_FAILURE);
  }
  
  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL){
    tokens[position] = token;
    position++;

    if (position >= bufsize){
      bufsize+= LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bifsize * sizeof(char));
      if(!tokens){
        fprintf(stderr, "Error reallocating memory to extend token size");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}



