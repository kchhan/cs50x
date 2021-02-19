// Implements a dictionary's functionality
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 130;

int dictionary_size = 0;
bool loaded = false;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Get index value from hashing
    int index = hash(word);

    // Set cursor to correct index at table to traverse
    node *cursor = table[index];

    // Check if linked list is empty
    if (cursor == NULL)
    {
        return false;
    }
    else
    {
        while (cursor != NULL)
        {
            if (strcasecmp(cursor->word, word) == 0)
            {
                return true;
            }
            
            cursor = cursor->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // source https://stackoverflow.com/questions/7666509/hash-function-for-string
    // http://www.cse.yorku.ca/~oz/hash.html
    unsigned long hash = 5381;
    int c = *word;

    c = tolower(c);

    while (*word != 0)
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        c = *word++;
        c = tolower(c);
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    // Word buffer whose size is max length of word
    char w[LENGTH];

 
    // Check every word in dictionary
    while(fscanf(input, "%45s", w) != EOF)
    {
        // Create new node to store word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
           return false;
        }
    
        // Copy word into node using strcpy
        strcpy(n->word, w);
        
        // Insert node into has table by using hash function first
        int index = hash(w);
        
        // Applend node to correct place (start of node is easiet)
        if (table[index] == NULL)
        {
            table[index] = n;
            table[index]->next = NULL;
        }
        else
        {
            // First set new node's next to what current index's next is
            n->next = table[index];

            // Set index's next to new node
            table[index] = n;
        }
        dictionary_size++;
    }

    fclose(input);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (!loaded) return 0;
    return dictionary_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over table array
    for (int i = 0; i < N; i++)
    {
        node* cursor = table[i];

        while(cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        if (i == N - 1 && cursor == NULL)
        {
            loaded = false;
            return true;
        }
    }
    
    return false;
}
