#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void convertLongToArray(long number, int *array);
int sumDigits(int number);
int countDigits(long number);

bool cardNumberLengthIsValid(int length);
int calculateCardChecksum(int digits[], int length);
bool cardChecksumIsValid(int checksum);
string getCardVendor(int digits[]);
string validateCardNumber(long number);

int main(void)
{
    long number = get_long("Number: ");

    printf("%s\n", validateCardNumber(number));
}

string validateCardNumber(long number)
{
    int length = countDigits(number);

    if (cardNumberLengthIsValid(length))
    {
        int digits[length];
        convertLongToArray(number, digits);

        int checksum = calculateCardChecksum(digits, length);

        if (cardChecksumIsValid(checksum))
        {
            // Checks for card type
            return getCardVendor(digits);
        }
    }

    return "INVALID";
}

// Checks whether or not the length of the given card number is within the min and max length
bool cardNumberLengthIsValid(int length)
{
    const int MAX_LENGTH = 16;
    const int MIN_LENGTH = 13;

    return length <= MAX_LENGTH && length >= MIN_LENGTH;
}

int calculateCardChecksum(int digits[], int length)
{
    // Checks for validity
    int checksum = 0;
    // Loop through the array of digits backwards, skipping the last digit and then skipping every other digit
    for (int i = length - 2 ; i >= 0; i -= 2)
    {
        // We then multiply each digit by 2, and add up the digits of the result
        checksum += sumDigits(digits[i] * 2);
    }

    // Now we add up the remaining digits (the ones we didn't multiply by 2)
    for (int i = length - 1; i >= 0; i -= 2)
    {
        checksum += digits[i];
    }

    return checksum;
}

// Returns whether or not the given checksum is valid
bool cardChecksumIsValid(int checksum)
{
    // Uses the modulus to check if the last digit in the checksum is 0, which indicates a valid card number
    return checksum % 10 == 0;
}

// Checks the first few digits of a card number for the vendor codes
string getCardVendor(int digits[])
{
    // Start by assuming an invalid card number
    string vendor = "INVALID";

    if (digits[0] == 4)
    {
        vendor = "VISA";
    }
    else if ((digits[0] == 3) && (digits[1] == 4 || digits[1] == 7))
    {
        vendor = "AMEX";
    }
    else if ((digits[0] == 5) && (digits[1] >= 1 && digits[1] <= 5))
    {
        vendor = "MASTERCARD";
    }

    return vendor;
}

// Converts a long into an array of individual digits
void convertLongToArray(long number, int *array)
{
    int i = 0;
    while (number > 0)
    {
        array[i] = number % 10;
        number /= 10;
        i++;
    }
    // Because we use the % above, the array is currently in reverse order
    // So here we reverse (back to correct) in place
    for (int j = 0; j < i / 2; j++)
    {
        int temp = array[j];
        array[j] = array[i - j - 1];
        array[i - j - 1] = temp;
    }
}

// Adds up the digits in a given integer
int sumDigits(int number)
{
    int sum = 0;

    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

// Counts how many digits are in the given long
int countDigits(long number)
{
    if (number == 0)
    {
        return 1;
    }

    return (int) floor(log10(number > 0 ? number : -number) + 1);
}
