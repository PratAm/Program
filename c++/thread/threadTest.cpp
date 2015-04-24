#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid;
    printf( "Hello, my pid is %d\n", getpid() );

    pid = fork();
    if( pid == 0 )
        printf( "I was forked! :D %d\n", getpid() );
    else
    {
        waitpid( pid, NULL, 0 );
        printf( "%d was forked!\n", pid );
    }
    return 0;
}
