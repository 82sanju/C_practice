#include<stdio.h>
#include<string.h>
#include <stdlib.h>


char *create_string() {
    char *s = malloc(100);

    fgets(s, 100, stdin);

    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '\n') {
            s[i] = '\0';
            break;
        }
        i++;
    }

    return s;
}

int main() {
    char *str = create_string();

    if (str != NULL) {
        printf("string: %s\n", str);
        free(str);
    }

    return 0;
}