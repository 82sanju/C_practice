#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node *next;

};

struct Node * createnode(int value){
    struct Node * newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode -> data=value;
    newNode -> next=NULL;
    return newNode;
};

void insertAtEnd(struct Node** head, int value){
    struct Node* newNode = createnode(value);
    if(*head ==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;

}

void display(struct Node* head){
    while(head!=NULL){
        printf("%d -> ", head->data);
        head =head->next;
    }
    printf("NULL\n");
}

int main(){

}