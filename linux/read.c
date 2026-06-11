#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_RDONLY);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    char buffer[100];
    int bytes;

    while ((bytes = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes);  // 1 = stdout
    }

    close(fd);
    return 0;
}