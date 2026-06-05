#include<stdio.h>
#include<string.h>

int main(){
char str[] = "Hello";

char *p = strchr(str, 'l');
printf("%s\n", p);
}