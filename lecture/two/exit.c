#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("missing command-line arguments\n");
        // error
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    // no errors
    return 0;
}

// echo $?
// see return integerj 