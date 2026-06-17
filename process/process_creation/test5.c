#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    int pid = fork();

    if (pid > 0) {
        // Parent (write integer)
        close(fd[0]);

        int num = 42;
        write(fd[1], &num, sizeof(num));

        close(fd[1]);
    } else {
        // Child (read integer)
        close(fd[1]);

        int received;
        read(fd[0], &received, sizeof(received));

        printf("Child received: %d\n", received);

        close(fd[0]);
    }

    return 0;
}