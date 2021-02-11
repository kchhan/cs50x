#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentenses(string text);
int calculate_grade(int letters, int words, int sentenses);

int main(void)
{
    // Declare variables
    int grade = 0;
    int l = 0;
    int w = 0;
    int s = 0;
    
    // Get user input for text
    string text = get_string("Text: \n");

    l = count_letters(text);
    w = count_words(text);
    s = count_sentenses(text);

    grade = calculate_grade(l, w, s);

    if (grade > 15)
    {
        printf("Grade 16+\n");
    } 
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);    
    }
}

int count_letters(string text)
{
    // Declare count
    int count = 0;
    
    // Count increases if char is alphabetical
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i])) 
        {
            count++;
        }
    }
    
    return count;
}

int count_words(string text)
{   
    // Declare count;
    int count = 0;
    
    // Count increases if char is space
    for (int i = 0, n = strlen(text); i < n; i++) 
    {
        if (isspace(text[i])) 
        {
            count++;
        }    
    }
    
    return count + 1;
}

int count_sentenses(string text)
{   
    // Declare count;
    int count = 0;
    
    // Count increases if char is ending punctuation
    for (int i = 0, n = strlen(text); i < n; i++) 
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63) 
        {
            count++;
        }    
    }
    
    return count;
}

int calculate_grade(int letters, int words, int sentenses)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    // L is letters per 100 words
    // S is senteneses per 100 words
    
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentenses / (float) words) * 100;

    return (int) round(0.0588 * L - 0.296 * S - 15.8);
}