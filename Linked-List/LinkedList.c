#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; // pointer of type (struct Node) named next
};

int isEmpty(struct Node* list){
    return (list == NULL);
}

void insertFirst(struct Node** head, int data){
    // 1. Create a new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    // 2. Fill its data 
    newnode->data = data;
    
    // 3. Make next of new node as head
    newnode->next = (*head);
 
    // 4. Move the head to point to
    // the new node
    (*head) = newnode;

}

void display(struct Node* list){
    if(isEmpty(list)){
        printf("List is Empty\n");
    }
    else{
        struct Node* temp = list;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main(){
    struct Node * Head = NULL; // created an Empty LL
    
    display(Head);
    insertFirst(&Head, 2);
    insertFirst(&Head, 3);
    insertFirst(&Head, 4);
    display(Head);

}