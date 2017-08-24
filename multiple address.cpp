#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Maximum number of children */
#define MAX_NO_CLD 10

int main ()
{
   int i, num_child, wtime, status,var=10;
   pid_t child_pid, mypid, parpid;


   mypid = getpid();
   parpid = getppid();
   printf("Parent: PID = %u, PPID = %u\n", mypid, parpid);
   printf("The address of Var is %d\n",&var);


   printf("Parent: Number of children = "); scanf("%d", &num_child);

   printf("\n");


   for (i=0; i<num_child; ++i) {

      child_pid = fork();


      if (child_pid == 0) {

         mypid = getpid();
         parpid = getppid();
         srand(mypid);
         wtime = 1 + rand() % 10;
         printf("The address of Var is %d\n",&var);
         printf("Child %d: PID = %u, PPID = %u, work time = %d\n",i, mypid, parpid, wtime);


         sleep(wtime);
         printf("\nChild %d: Work done...\n", i);


         exit(i);
      }


   }

   for (i=0; i<num_child; ++i) {

      wait(&status);


      printf("Parent: Child %d terminates...\n", WEXITSTATUS(status));
   }

   printf("\nParent terminates...\n");

   exit(0);
}
