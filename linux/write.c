#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd < 0) return 1;

    char *data = "Hello, File Handling!\n";

    write(fd, data, 24);

    close(fd);
    return 0;
}