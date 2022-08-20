#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenate(char *a, char *b) {
    size_t aSize = strlen(a);
    size_t bSize = strlen(b);

    size_t newSize = (aSize + bSize) + 1;

    char *result = malloc(newSize);

    strcpy(result, a);

    result = result + aSize;

    strcpy(result, b);

    result = result - aSize;

    return result;
}

int main(void) {
    char *result = concatenate("testing ", "concat");

    printf("%s\n", result);

    free(result);
    
    return 0;
}