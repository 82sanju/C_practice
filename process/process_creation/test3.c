#include<stdio.h>

int main(){
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        char buf[100];
        read(fd[0], buf, 100);
        printf("Child got: %s\n", buf);
    } else {
        write(fd[1], "Hello", 6);
    }



    //--------------------------------

    // int fd[2];
    // pipe(fd);

    // if (fork() == 0) {
    //     char buf[10];
    //     read(fd[0], buf, 10);
    //     printf("Child: %s\n", buf);
    // } else {
    //     sleep(2);
    //     write(fd[1], "Hi", 3);
    //     printf("Parent done\n");
    // }

}




