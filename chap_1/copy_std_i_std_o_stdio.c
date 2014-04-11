#include <stdio.h>

int main(int argc, char* argv[])
{
    int c;
    while ((c = getc(stdin)) != EOF)
    {
        if (putc(c, stdout) == EOF)
        {
            printf("output error");
            return 1;
        }
    }

    if (ferror(stdin))
    {
        printf("input error");
        return 1;
    }

    return 0;
}
        
