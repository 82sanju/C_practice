#include <stdio.h>

int main() {
    FILE *src = fopen("source.txt", "r");
    FILE *dest = fopen("dest.txt", "w");

    if (src == NULL || dest == NULL) return 1;

    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}