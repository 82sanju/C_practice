#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("Child Process\n");
        printf("PID = %d, PPID = %d\n", getpid(), getppid());
    } else {
        printf("Parent Process\n");
        printf("PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}