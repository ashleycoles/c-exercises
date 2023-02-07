#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int MAX_HEIGHT = 8;
    const int MIN_HEIGHT = 1;

    int height = 0;

    // Continue prompting if the input was invalid
    while (height > MAX_HEIGHT || height < MIN_HEIGHT)
    {
        height = get_int("Height: ");
    }

    int blocks = 1;

    // For each row
    for (int i = 0; i < height; i++)
    {
        int padding = height - blocks;
        // Create the left side padding
        for (int j = 0; j < padding; j++)
        {
            printf(" ");
        }
        // Create the left pyramid
        for (int j = 0; j < blocks; j++)
        {
            printf("#");
        }

        printf("  ");
        // Create the right pyramid
        for (int j = 0; j < blocks; j++)
        {
            printf("#");
        }

        printf("\n");
        blocks++;
    }

}