#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(void)  {

    pid_t child_pid, wpid, pid;
    int status = 0;
    int i;

    int a[3] = {1, 2, 1};
    for(i = 1; i < 3; i++)  {
        printf("i = %d\n", i);
        pid = getpid();
        printf("pid after i = %d\n", pid);
        if((child_pid = fork()) == 0)  {
            printf("In child process\n");
            pid = getpid();
            printf("pid in child process is %d\n", pid);
            /* Is a child process */
            if(a[i] < 2)  {
                printf("Should be accept\n");
                _exit(1);
            } else  {
                printf("Should be reject\n");
                _exit(0);
            }
        }
    }

    if(child_pid > 0)  {
        /* Is the parent process */
        pid = getpid();
        printf("parent_pid = %d\n", pid);
        wpid = wait(&status);
        if(wpid != -1)  {
            printf("Child's exit status was %d\n", status);
            if(status > 0)  {
                printf("Accept\n");
            } else  {
                printf("Complete parent process\n");
                if(a[0] < 2)  {
                    printf("Accept\n");
                } else  {
                    printf("Reject\n");
                }
            }
        }
    }
    return 0;
}
