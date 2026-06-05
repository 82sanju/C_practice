#include<stdio.h>


void reverse(char *s) {
    if (s == NULL || *s == '\0') return;
    char *start = s;
    char *end = s;

    //
    while (*end != '\0') end++;
    end--; // last char
    //



    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main(){
    char s[20]="sanju";
    reverse(s);
    printf("%s\n",s);

}