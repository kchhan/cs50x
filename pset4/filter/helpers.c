#include "helpers.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Average greyscale
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);

            // Convert the colors
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate sepia colors
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // Cap the colors in case they go over 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Convert the colors
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Copies image
    RGBTRIPLE arr[height][width];
    for (int a = 0; a < height; a++) 
    {
        for (int b = 0; b <= width; b++)
        {
            arr[a][b] = image[a][b];
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        // Loops through and swaps the pixels
        for (int k = 0, l = width - 1; k < width; k++, l--)
        {
            image[i][k].rgbtRed = arr[i][l].rgbtRed;
            image[i][k].rgbtGreen = arr[i][l].rgbtGreen;
            image[i][k].rgbtBlue = arr[i][l].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copies image
    RGBTRIPLE arr[height][width];
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            arr[a][b] = image[a][b];    
        }
    }
    
    // Iterate through each block and block avg
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = 0;
            int blue = 0;
            int green = 0;
            float n = 0;
            
            // Top Left
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += arr[i - 1][j - 1].rgbtRed;
                green += arr[i - 1][j - 1].rgbtGreen;
                blue += arr[i - 1][j - 1].rgbtBlue;
                n++;
            }
            
            // Top
            if (i - 1 >= 0)
            {
                red += arr[i - 1][j].rgbtRed;
                green += arr[i - 1][j].rgbtGreen;
                blue += arr[i - 1][j].rgbtBlue;
                n++;
            }
            
            // Top Right
            if (i - 1 >= 0 && j + 1 < width)
            {
                red += arr[i - 1][j + 1].rgbtRed;
                green += arr[i - 1][j + 1].rgbtGreen;
                blue += arr[i - 1][j + 1].rgbtBlue;
                n++;
            }
            
            // Left
            if (j - 1 >= 0)
            {
                red += arr[i][j - 1].rgbtRed;
                green += arr[i][j - 1].rgbtGreen;
                blue += arr[i][j - 1].rgbtBlue;
                n++;
            }
            
            // Middle
            red += arr[i][j].rgbtRed;
            green += arr[i][j].rgbtGreen;
            blue += arr[i][j].rgbtBlue ;
            n++;
            
            // Right
            if (j + 1 < width)
            {
                red += arr[i][j + 1].rgbtRed;
                green += arr[i][j + 1].rgbtGreen;
                blue += arr[i][j + 1].rgbtBlue;
                n++;
            }
            
            // Bottom Left
            if (i + 1 < height && j - 1 >= 0)
            {
                red += arr[i + 1][j - 1].rgbtRed;
                green += arr[i + 1][j - 1].rgbtGreen;
                blue += arr[i + 1][j - 1].rgbtBlue;
                n++;
            }
            
            // Bottom
            if (i + 1 < height)
            {
                red += arr[i + 1][j].rgbtRed;
                green += arr[i + 1][j].rgbtGreen;
                blue += arr[i + 1][j].rgbtBlue;
                n++;
            }
            
            // Bottom Right
            if (i + 1 < height && j + 1 < width)
            {
                red += arr[i + 1][j + 1].rgbtRed;
                green += arr[i + 1][j + 1].rgbtGreen;
                blue += arr[i + 1][j + 1].rgbtBlue;
                n++;
            }
            
            // Change block to averages;
            image[i][j].rgbtRed = (int) round(red / n);
            image[i][j].rgbtGreen = (int) round(green / n);
            image[i][j].rgbtBlue = (int) round(blue / n);
        }
    }
    return;
}