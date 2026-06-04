#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *newNode;
    //create node
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 10;
    newNode->next = head;
    head = newNode;

    // Display list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}