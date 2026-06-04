#include <stdio.h>

int main() {
    volatile int x = 5;

    printf("x = %d\n", x);
    x = 10;

    printf("Updated x = %d\n", x);

    return 0;
}