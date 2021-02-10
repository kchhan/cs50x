#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    int end;
    int years = 0;

    // Prompt for start size
    do
    {
        start = get_int("Start size: \n");
    }
    while (start < 9);
    
    // Prompt for end size
    do
    {
        end = get_int("End size: \n");
    }
    while (end < start);

    // Calculate number of years until we reach threshold
    while (start < end) 
    {
        int born = start / 3;
        int dead = start / 4;
        
        start = start + born - dead;
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}