#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file.txt", O_CREAT | O_WRONLY, 0644);

    write(fd, "Hello File\n", 11);

    close(fd);
    return 0;
}