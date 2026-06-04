#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;

    // create nodee
    for (int i = 1; i <= 3; i++) {

        struct Node *newNode = malloc(sizeof(struct Node));

        newNode->data = i * 10;
        newNode->next = head;
        head = newNode;
    }

    //traverse
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}