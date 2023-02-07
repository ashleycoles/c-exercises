#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string input = get_string("Text: ");

    int letters = count_letters(input);
    int words = count_words(input);
    int sentences = count_sentences(input);
    // Average number of letters per 100 words
    float L = (float)letters / (float)words * 100;
    // Average number of sentences per 100 words
    float S = (float)sentences / (float)words * 100;
    // Coleman-Liau index formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);
    // Check thresholds for output
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_sentences(string text)
{
    int length = strlen(text);

    int count = 0;
    // Check each character to see if it's a sentence ending puctuation
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }

    return count;
}

int count_words(string text)
{
    int length = strlen(text);

    int count = 1;
    // Check each character to see if it's a space
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }

    return count;
}

int count_letters(string text)
{
    int length = strlen(text);
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int alphabet_length = strlen(alphabet);

    int count = 0;
    // Check each character against the alphabet
    for (int i = 0; i < length; i++)
    {
        // For each character in the input, check it against the alphabet
        for (int j = 0; j < alphabet_length; j++)
        {
            // Convert each letter to lowercase
            if (tolower(text[i]) == alphabet[j])
            {
                count++;
                break;
            }
        }
    }

    return count;
}