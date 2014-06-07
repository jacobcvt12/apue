#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;

    if ((fd = creat("file.hole", FILE_MODE)) < 0)
    {
        printf("creat error\n");
        return 1;
    }

if 
