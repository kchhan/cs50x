#include <stdio.h>
#include <cs50.h>

int main(void)

{
    // Declare num
    int num = 0;
    
    // Prompt for height
    do 
    {
        num = get_int("Height: \n");
    }
    while (num < 1 || num > 8);
    
    // Make pyramid
    for (int i = 0; i < num; i++)
    {
        // Spaces before left pyramid
        for (int k = 0; k < num - i - 1; k++)
        {
            printf(" ");
        }
        
        // Left pyramid
        for (int j = 0; j <= i; j++) 
        {
            printf("#");
        }
        
        // spaces in between
        printf("  ");
        
        // Right pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}