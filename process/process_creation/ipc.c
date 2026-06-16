#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);   // fd[0] = read, fd[1] = write

    int pid = fork();

    if (pid > 0) {
        // Parent Process
        close(fd[0]);

        char msg[] = "Hello from Parent";
        write(fd[1], msg, strlen(msg) + 1);

        close(fd[1]);
    } 
    else {
        // Child Process
        close(fd[1]);  

        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);

        close(fd[0]);
    }

    return 0;
}