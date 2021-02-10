#include <stdio.h>
#include <cs50.h>

int main(void)

{
    // Declare change
    float change;
    // Declare number of coins
    int count = 0;
    
    // Get change amount
    do
    {
        change = get_float("Change owed: \n");
    }
    while (change < 0);
 
    // Change from dollars to cents
    change = change * 100;
    // Change from float to int
    change = (int)(change + 0.5);
    
    // Quarters
    while (change >= 25)
    {
        change -= 25;
        count++;
    };

    // Dimes
    while (change >= 10)
    {
        change -= 10;
        count++;
    };

    // Nickles
    while (change >= 5)
    {
        change -= 5;
        count++;
    };

    // Pennies
    while (change > 0)
    {
        change -= 1;
        count++;
    };

    printf("%i\n", count);
}