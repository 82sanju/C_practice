#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(sizeof(int));  // allocate 1 int

    if (p == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    *p = 42;   // dereferencing
    printf("Value: %d\n", *p);

    free(p);   // release memory
    return 0;
}