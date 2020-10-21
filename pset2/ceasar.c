#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

int main( int argc, char *argv[])
{
    printf("Number of arguments %i\n", argc);
    printf("Given argument:  %s\n", argv[1]);
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
