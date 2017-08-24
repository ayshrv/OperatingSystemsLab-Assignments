#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int fn(int);
int main(int argc, char *argv[]){
  int x = fn(atoi(argv[argc-1]));
  pid_t pid = getpid();
  if(argc > 2){
    sprintf(argv[argc-1], "%d", x);
    printf("pid=%d result=%d;\n", pid, x);
    execv(argv[1], argv+1);
  }
  else if(argc == 2)
    printf("pid=%d result=%d;\n", pid, x);
  return 0;
}
int fn(int x){
  return x/2;
}
