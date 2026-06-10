#include <fcntl.h>
#include <unistd.h>

int main() {
    char buf[20];

    int fd = open("file.txt", O_RDONLY);

    int n = read(fd, buf, 20);

    write(1, buf, n);

    close(fd);
    return 0;
}