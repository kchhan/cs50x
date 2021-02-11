#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Prototype
int validate_key(string key);
string to_uppercase(string key);
string substitute_string(string plaintext, string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    
    // Not enough arguments
    if (argc != 2) 
    {
        printf("./subtitution KEY");
        return 1;
    }
    
    // Key not right size
    if (strlen(key) != 26) 
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    // Validates key before cyphering
    int validity = validate_key(key);
    
    if (validity == 1)
    {
        printf("Key must contain alphabetic characters\n");
        return 1;
    }
        
    if (validity == 2)
    {
        printf("Key must not contain repeated characters\n");
        return 1;
    }
    
    // Makes key all same case size
    key = to_uppercase(key);

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");
    
    // Converts string
    string substitution = substitute_string(plaintext, key);
    
    printf("ciphertext: %s\n", substitution);
}

int validate_key(string key)
{
    // 26 letters
    int map[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    
    // Makes key all same case size
    key = to_uppercase(key);
    
    // Loops through key and makes sure all is alphabetical and singley used
    for (int i = 0; i < 26; i++)
    {
        // alphabetical
        if (!isalpha(key[i]))
        {
            return 1;
        }
        
        // singley used
        if (map[key[i] - 65] == 0)
        {
            return 2;    
        }
        // 0 means letter was already used before so throw error
        map[key[i] - 65]--;
        
    }
    return 0;
}

string to_uppercase(string key)
{
    for (int i = 0; i < 26; i++) 
    {
        key[i] = toupper(key[i]);
    }
    return key;
}

string substitute_string(string plaintext, string key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (!isalpha(plaintext[i])) 
        {
            continue;
        } 
        else 
        {
            // Upper 65 - 90 Lower 97 - 122
            if (plaintext[i] >= 97 && plaintext[i] <= 122)
            {
                // Change text
                plaintext[i] = key[plaintext[i] - 97];
                // Keep case
                plaintext[i] = tolower(plaintext[i]);
            }
            else
            {
                // Change text
                plaintext[i] = key[plaintext[i] - 65];
                // Keep case
                plaintext[i] = toupper(plaintext[i]);
            }
        }
    }
    return plaintext;
}