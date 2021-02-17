#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
}

// int main(void)
// {
//     string s = "HI!";
//     printf("%p\n", s);
// }

// int main(void)
// {
//     int n = 50;
//     int *p = &n;
//     printf("%i\n", *p);
// }

// typedef char *string