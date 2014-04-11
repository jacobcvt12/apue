#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    if (argc > 0)
        perror(argv[0]);

    return 0;
}
