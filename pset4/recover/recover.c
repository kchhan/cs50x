#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Define new type BYTE
typedef uint8_t BYTE;

const int CHUNK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover input.raw\n");
        return 1;
    }

    // Open memory card
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Initialize count for new jpg files
    int count = 0;
    
    // There is an open file
    bool openfile = false;
    
    // Initialize pointer for new jpg files
    FILE *img = NULL;

    // Create buffer
    BYTE buffer[CHUNK_SIZE];
    while (fread(buffer, CHUNK_SIZE, 1, input))
    {
        // Start of a new jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If a file is open close it before making new file
            if (img != NULL)
            {
                fclose(img);
                openfile = false;
            }
            
            // Create new file
            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            
            // Increment count for next jpg
            count++;
            
            // Open img file to write to
            img = fopen(filename, "w");
            openfile = true;
            
            // Write the current buffer to img
            fwrite(buffer, CHUNK_SIZE, 1, img);
        }
        // Not the start of a new jpg
        else
        {
            // Only write if there is a file already open
            if (openfile)
            {
                fwrite(buffer, CHUNK_SIZE, 1, img);    
            }
        }
    }

    // close files
    fclose(img);
    fclose(input);
    return 0;
}

// read files
// fread(data, size, number, inptr);
// fread returns number of items of size size were read

// make new jpeg
// ###.jpeg 000.jpeg
// sprintf(filename, "%03i.jpg", 2);
// FILE *img = fopen(filename, "w");
// fwrite(data, size, number, outptr) outptr is the jpg

// PSUDOCODE
// 1. open memory card
// 2. repeat until end of card
//      a. read 512 bytes into buffer
//      b. if start of new jpg
//          i. if first jpg 000.jpeg else count up
//          ii. continue 512 blocks until next jpg
// 3. close file