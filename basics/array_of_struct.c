#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    float marks;
};

int main() {
    int n = 3;

    struct Student *arr = malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        arr[i].id = i + 1;
        arr[i].marks = 80 + i;
    }

    for (int i = 0; i < n; i++) {
        printf("%d %.2f\n", arr[i].id, arr[i].marks);
    }

    free(arr);
}