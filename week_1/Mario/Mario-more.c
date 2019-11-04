#include <cs50.h>
#include <stdio.h>

// function to get a number from user between 2 numbers
int get_right_int(string prompt);

int main(void)
{
    int height = get_right_int("Height: ");
    //starting at 0, for each number in "height"...
    for (int i = 0; i < height; i++)
    {
        printf("%*s", height - i - 1, ""); // trick to save a for loop
        
        for (int j = 0; j <= i; j++)
        {
            printf("#");       
        }
        
        printf("  ");
        
        for (int k = 0; k <= i; k++)
        {
            printf("#");       
        }
       
        printf("\n");
    }
    
}

int get_right_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}
