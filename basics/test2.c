#include <stdio.h>

int main() {
    int x = 15;
    int *p = &x;

    printf("%d\n", *p);
    return 0;
}