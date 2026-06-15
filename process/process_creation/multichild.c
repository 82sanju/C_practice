//return 0 prevents exponential growth


// #include <unistd.h>

// int main() {
//     while (1) {
//         fork();
//     }
// }




#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            printf("Child %d, PID = %d\n", i, getpid());
            return 0;
        }
    }

    return 0;
}