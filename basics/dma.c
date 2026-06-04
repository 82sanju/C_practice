#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(sizeof(int));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    *p = 42;
    printf("Value: %d\n", *p);
    printf("%p\n",p);

    free(p);
    p = NULL;
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Value: %d\n", *p);
    printf("%p\n",p);
    return 0;
}