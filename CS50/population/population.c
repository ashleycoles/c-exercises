#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);


    // Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    // Calculate number of years until we reach threshold
    int years = 0;
    int population = startSize;

    while (population < endSize)
    {
        int births = population / 3;
        int deaths = population / 4;

        population += births;
        population -= deaths;
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}
