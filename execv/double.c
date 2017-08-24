#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define TRUE 1
#define FLASE 0

int isnum(char *);

int main(int argc, char* argv[]) {
int pid = getpid();
  printf("Executing with Process ID %d...\n", getpid());
  if(isnum(argv[1]) == TRUE) {
    printf("Result: %d.\n", atoi(argv[1]) * 2);
  }
  else {
    sprintf(argv[argc-1], "%d", atoi(argv[argc - 1]) * 2);
    printf("pid=%d result=%d;\n", pid, atoi(argv[argc - 1]));
    execv(argv[1], argv+1);
    if(execvp(argv[1], argv + 1) < 0) {
      printf("Error in execution! Aborting...\n");
      exit(1);
    }
  }
  return 0;
}

int isnum(char* string) {
  if(string[0] != '\0') {
    return isdigit(string[0]) && isnum(string + 1);
  }
  else {
           {
                return TRUE;
           }
  }
}
