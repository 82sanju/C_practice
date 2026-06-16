#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int p1[2], p2[2];

    pipe(p1);
    pipe(p2);

    int pid = fork();

    if (pid > 0) {
        // Parent
        close(p1[0]);
        close(p2[1]);

        char msg[] = "Ping from parent";
        write(p1[1], msg, strlen(msg) + 1);

        char buffer[100];
        read(p2[0], buffer, sizeof(buffer));

        printf("Parent received: %s\n", buffer);

        close(p1[1]);
        close(p2[0]);
    } else {
        // Child
        close(p1[1]);
        close(p2[0]);

        char buffer[100];
        read(p1[0], buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);

        char reply[] = "Pong from child";
        write(p2[1], reply, strlen(reply) + 1);

        close(p1[0]);
        close(p2[1]);
    }

    return 0;
}