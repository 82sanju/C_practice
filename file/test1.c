#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "w");

    if (fp == NULL) {
        printf("Error\n");
        return 1;
    }

    char name[50];
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);

    fprintf(fp, "Name: %s", name);

    fclose(fp);
}