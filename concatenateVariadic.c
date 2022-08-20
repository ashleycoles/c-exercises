#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char * v_concatenate(int num, ...) {
    va_list vaList, vaListCopy;
    size_t totalSize = 0;
    char *result;

    va_start(vaList, num);
    va_copy(vaListCopy, vaList);

    for (int i = 0; i < num; i++) {
        char *arg = va_arg(vaListCopy, char *);
        totalSize += strlen(arg) * sizeof(char);
    }
    
    result = malloc(totalSize);

    for (int i = 0; i < num; i++) {
        char *arg = va_arg(vaList, char *);
        size_t size = strlen(arg) * sizeof(char);
        strcpy(result, arg);
        result += size;
    }

    va_end(vaList);
    va_end(vaListCopy);

    result -= totalSize;

    return result;
}


int main(void) {
    char *result = v_concatenate(3, "Testing", " string", " concat");

    printf("%s\n", result);

    free(result);
    
    return 0;
}