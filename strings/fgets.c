#include<stdio.h>
int main(){
    char name[50];
    fgets(name , sizeof(name),stdin);
    printf("name: %s",name);
}