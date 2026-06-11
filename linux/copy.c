#include <fcntl.h>
#include <unistd.h>

int main() {
    int src = open("source.txt", O_RDONLY);
    int dest = open("dest.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (src < 0 || dest < 0) return 1;

    char buffer[100];
    int bytes;

    while ((bytes = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    close(src);
    close(dest);

    return 0;
}