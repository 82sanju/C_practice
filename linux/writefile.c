#include <stdio.h>

int main() {
    FILE *fp = fopen("file.txt", "w");

    if (fp == NULL) return 1;

    fprintf(fp, "Hello using fprintf!\n");

    fclose(fp);
    return 0;
}