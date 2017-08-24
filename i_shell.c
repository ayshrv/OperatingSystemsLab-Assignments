#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int shell_cd(char **args);
int shell_exit(char **args);

char *builtin_str[] =
{
  "cd",
  "exit"
};

int (*builtin_func[]) (char **) =
{
  &shell_cd,
  &shell_exit
};

int shell_cd(char **args)
{
  if (args[1] == NULL)
    fprintf(stderr, "Error: Argument not supplied with cd\n");
  else
  {
    if (chdir(args[1]) != 0)
      perror("Error");
  }
  return 1;
}

int shell_exit(char **args)
{
  return 0;
}

int shell_launch(char **args)
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0)
  {
    if (execvp(args[0], args) == -1)
    {
      perror("Error");
      exit(EXIT_FAILURE);
    }  
  }
  else if (pid < 0)
    perror("Error");
  else
  {
    do
    {
      waitpid(pid, &status, WUNTRACED);
    } while(!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int shell_execute(char **args)
{
  int i;

  if (args[0] == NULL)
    return 1;

  for (i = 0; i < 2; i++)
  {
    if (strcmp(args[0], builtin_str[i]) == 0)
      return (*builtin_func[i])(args);
  }

  return shell_launch(args);
}

#define BUFFSIZE 1024
char *shell_read_line(void)
{
  int buffersize = BUFFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * buffersize);
  int c;

  if (!buffer)
  {
    fprintf(stderr, "Allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    c = getchar();

    if (c == EOF || c == '\n')
    {
      buffer[position] = '\0';
      return buffer;
    } 
    else
      buffer[position] = c;
    position++;
  }
}

#define TOK_BUFFSIZE 64
#define LSH_TOK_DELIM " \t\r\n"
char **shell_split_line(char *line)
{
  int buffsize = TOK_BUFFSIZE, position = 0;
  char **tokens = malloc(buffsize * sizeof(char*));
  char *token, **tokens_backup;

  if (!tokens)
  {
    fprintf(stderr, "Allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL)
  {
    tokens[position] = token;
    position++;
    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

void shell_loop(void)
{
  char *line;
  char **args;
  int status;

  do
  {
    printf("my_shell> ");
    line = shell_read_line();
    args = shell_split_line(line);
    status = shell_execute(args);

    free(line);
    free(args);

  } while(status);
}

int main(int argc, char **argv)
{
  shell_loop();
  return 0;
}