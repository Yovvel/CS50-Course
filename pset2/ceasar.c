#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char *argv[])
{
    if(argc != 2 || !isdigit(argv[1][0]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == 0)
    {
        return 1;
    }
    }
     int key = atoi(argv[1]);
    string  plainText = get_string("Plaintext: ");

    printf("ciphertext: ");
    for(int i = 0, n = strlen(plainText); i < n; i++)
    {
        if isupper(plainText[i])
        {
           printf("%c", (((plainText[i] + key)-65)%26)+65);
        }
        else if islower(plainText[i])
        {
           printf("%c", (((plainText[i] + key)-97)%26)+97);
        }
        else
        {
            printf("%c", plainText[i]);
        }

    }
    printf("\n");
    return 0;
}
