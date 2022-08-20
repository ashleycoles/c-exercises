#include <stdio.h>

size_t str_len(char *string) {
    size_t length = 0;

    while (string[length] != '\0') {
        length++;
    }

    return length;
}

int main(void) {
    size_t result = str_len("testing");

    printf("%zu\n", result);
    
    return 0;
}