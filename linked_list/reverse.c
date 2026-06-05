#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

struct Node* insert(struct Node* head , int val){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode -> data=val;
    newNode ->next =head;
    return newNode;

}

void printList(struct Node* head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");

}
int main(){
    struct Node* head =NULL;
    // create list 
    head =insert(head,10);
    head=insert(head,15);
    head=insert(head,20);

    printf("Original: ");
    printList(head);

    head=reverse(head);
    printf("reversed: ");
    printList(head);

    freeList(head);
    return 0;

}