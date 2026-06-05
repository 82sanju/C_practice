#include<stdio.h>
#include<string.h>
int main(){
    char name[50];
    fgets(name , sizeof(name),stdin);
    printf("name:%s",name);  //reads new line also
    printf("size %ld\n",strlen(name));
}