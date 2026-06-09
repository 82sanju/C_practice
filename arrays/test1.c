#include<stdio.h>
#include<stdlib.h>

int main(){
    // int *p = malloc(5 * sizeof(int));
    // printf("%ld\n", sizeof(p));

    int *p = malloc(sizeof(int));
    *p = 10;
    free(p);
    printf("%d", *p);
}