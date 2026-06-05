#include<stdio.h>
#include<string.h>


int my_strlen(char *str) {
    int count = 0;

    while (*str != '\0') {
        count++;
        str++;
    }

    return count;
}

int main(){
    char str[] = "Hello World";
    char *p = strstr(str, "World");
    printf("%s\n", p);
    int z= my_strlen(p);
    printf("%d\n",z);


}