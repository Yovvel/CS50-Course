#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    printf("%i\n", key);
    string  plainText = get_string("Plaintext: ");
    printf("Cypertext: ");
    for(int i = 0, n = strlen(plainText); i < n; i++)
    {
        printf("%c", (plainText[i] + key));
    }
    printf("\n");

}
