#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    int pid = fork();

    if (pid > 0) {
        close(fd[0]);

        int arr[5] = {1, 2, 3, 4, 5};
        write(fd[1], arr, sizeof(arr));

        close(fd[1]);
    } else {
        close(fd[1]);

        int arr[5];
        read(fd[0], arr, sizeof(arr));

        printf("Child received array: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        close(fd[0]);
    }

    return 0;
}