#include<stdio.h>
#include<string.h>

void my_strcat(char *dest, char *src) {
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

int main(){

    char str1[20] = "hello";
    char str2[] = " world";
    char str3[10]="hii";

    strcat(str1, str2);
    my_strcat(str3,str2);
    printf("str1:%s\n", str1);
    printf("str3:%s\n", str3);


}