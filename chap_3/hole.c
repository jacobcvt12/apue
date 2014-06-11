#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int     fd;

    if ((fd = creat("file.hole", FILE_MODE)) < 0)
    {
        fprintf(stderr, "creat error");
        return 1;
    }

    if (write(fd, buf1, 10) != 10)
    {
        fprintf(stderr, "buf1 write error");
        return 1;
    }
    /* offset now = 10 */

