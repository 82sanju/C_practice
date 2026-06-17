#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[30];

    printf("Enter something: ");
    scanf("%s", buffer);  // BLOCKS here

    printf("You entered: %s\n", buffer);
    return 0;
}