#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get numbers from user
    long x = get_long("x: ");
    long y = get_long("y: ");
    
    printf("%li\n", x + y);
}
