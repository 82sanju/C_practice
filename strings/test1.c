#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "sanju";
    //char str1
    // printf("%s\n", str1);
    // printf("Length = %zu\n", strlen(str1));
    char str2[10];
    char str3[20];

    strcpy(str2, str1);
    printf("%s\n", str2);
    // printf("Length = %zu\n", strlen(str1));


    strncpy(str3, str1, 10);
    printf("Length = %zu\n", strlen(str3));
    str3[3] = '\0';
    printf("%s\n",str3);
    printf("str3 Length = %zu\n", strlen(str3));


    //compare

    strcmp("abc", "abc");  // 0
    strcmp("abc", "abd");  // < 0
    strcmp("abd", "abc");  // > 0




    return 0;
}