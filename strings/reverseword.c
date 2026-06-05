#include<stdio.h>
#include<string.h>



void reverse_range(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}


void reverse_words(char *s) {
    if (s == NULL || *s == '\0') return;

    char *start = s;
    char *end = s;
    while (*end) end++;
    end--;
    reverse_range(start, end);


    char *word_start = s;
    while (*s) {
        if (*s == ' ') {

            reverse_range(word_start, s - 1);
            word_start = s + 1;

        }
        s++;

    }
    reverse_range(word_start, s - 1);
}

int main() {
    char str[] = "i am sanju";

    reverse_words(str);
    printf("%s\n", str);

    return 0;
}