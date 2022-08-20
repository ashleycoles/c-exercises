#include <stdio.h>
#include <stdarg.h>

int sum(int num, ...) {
    va_list vaList;
    int result, i;

    va_start(vaList, num);

    result = 0;

    for (i = 0; i < num; i++) {
        result += va_arg(vaList, int);
    }

    va_end(vaList);

    return result;
}


int main(void) {
    int result = sum(3, 1, 2, 3);

    printf("%i\n", result);
    
    return 0;
}