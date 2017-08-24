#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int counter = 0;
int main()
{
    printf("--beginning of program\n");

    pid_t pid = fork();
    // pid_t pid2 = fork();
    // pid_t pid3 = fork();
    // cout<<"hello"<<endl;
    cout<<pid<<endl;

    if (pid == 0)
    {
	    cout<<pid<<endl;
        // child process
        int i = 0;
        for (; i < 10; ++i)
        {
            printf("child process: counter=%d\n", ++counter);
        }
    }
    else if (pid > 0)
    {
	    cout<<pid<<endl;
        // parent process
        int j = 0;
        for (; j < 10; ++j)
        {
            printf("parent process: counter=%d\n", ++counter);
        }
    }
    else
    {
        // fork failed
        printf("fork() failed!\n");
        return 1;
    }

    printf("--end of program--\n");

    return 0;
}