#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const int KEY_LENGTH = 26;

void cipher(string plaintext, string key);
bool keyIsValid(string key);
bool keyContainsValidChars(string key);
bool keyHasNoDuplicates(string key);

int main(int argc, string argv[])
{
    // Check for the correct number of command line args
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Makes sure the key is the correct length
    if (!keyIsValid(key))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    cipher(plaintext, key);

    printf("ciphertext: %s\n", plaintext);
}

void cipher(string plaintext, string key)
{
    int plaintextLen = strlen(plaintext);
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int alphabetLen = strlen(alphabet);

    // Loop through the plain text
    for (int i = 0; i < plaintextLen; i++)
    {
        // Skip anything that isn't a letter
        if (!isalpha(plaintext[i]))
        {
            continue;
        }

        char replacement;

        for (int j = 0; j < alphabetLen; j++)
        {
            if (tolower(plaintext[i]) == alphabet[j])
            {
                replacement = key[j];
                break;
            }
        }
        // Perform the actual substitution matching original case
        if (islower(plaintext[i]))
        {
            plaintext[i] = tolower(replacement);
        }
        else
        {
            plaintext[i] = toupper(replacement);
        }
    }
}

// Validates a given key
bool keyIsValid(string key)
{
    return strlen(key) == KEY_LENGTH && keyContainsValidChars(key) && keyHasNoDuplicates(key);
}

// Ensures a given key only contains characters from the alphabet
bool keyContainsValidChars(string key)
{
    // Check each char is in the alphabet
    for (int i = 0; i < KEY_LENGTH; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }

    return true;
}

// Ensures a given key doesn't contain any duplicate letters (case insensitive)
bool keyHasNoDuplicates(string key)
{
    // Loop through the chars in key, for each char in key
    for (int i = 0; i < KEY_LENGTH; i++)
    {
        for (int j = 0; j < KEY_LENGTH; j++)
        {
            // Make sure we aren't comparing the current char against itself
            if (i == j)
            {
                continue;
            }
            // If we get a match here, that means that the same char occurs more than once
            if (tolower(key[i]) == tolower(key[j]))
            {
                return false;
            }
        }
    }

    return true;
}