#include <stdio.h>
#include <sys/wait.h> /* for pid_t type */
#include <string.h> /* for strlen */
#include <unistd.h> /* for fork and execlp*/

#define MAXLINE 4096

int main(void)
{
    char    buf[MAXLINE];
    pid_t   pid;
    int     status;

    printf("%% "); /* print promt (printf require && to print %) */
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */

        if ((pid = fork()) < 0)
        {
            fprintf(stderr, "fork error\n");
            return 1;
        } 
        else if (pid == 0) /* child */
        {
            execlp(buf, buf, (char*)0);
            fprintf(stderr, "couldn't execute: %s\n", buf);
            return 127;
        }

        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            fprintf(stderr, "waitpid error\n");
            return 1;
        }

        printf("%% ");
    }

    return 0;
}
