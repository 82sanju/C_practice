#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0) {
        printf("Child running\n");
    } else {
        wait(NULL);
        printf("Parent after child\n");
    }

    return 0;
}