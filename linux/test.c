#include <unistd.h>

int main() {
    // write(1, "Hello System Call\n", 19);
    write(1, "Hello", 6);
    return 0;
}