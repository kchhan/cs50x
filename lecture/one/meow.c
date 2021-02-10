#include <cs50.h>
#include <stdio.h>

// Prototype
void meow(void)

int main(void)
{
    for (int i = 0; i < 3; i++) 
    {
        meow();
    }
}

void meow(int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("meow\n");    
    }
}