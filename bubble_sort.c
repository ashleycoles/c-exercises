#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int *numbers, size_t len);

int main (void)
{
    int numbers[10] = {5, 3, 2, 9, 4, 1, 6, 8, 7, 10};
    bubble_sort(numbers, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%i\n", numbers[i]);
    }
}

void bubble_sort(int *numbers, size_t len)
{
    bool changed = false;

    for (int i = 0; i < len - 2; i++)
    {
        if (numbers[i] > numbers[i + 1])
        {
            int tmp = numbers[i];
            numbers[i] = numbers[i + 1];
            numbers[i + 1] = tmp;
            changed = true;
        }
    }

    if (changed)
    {
        bubble_sort(numbers, len);
    }
}