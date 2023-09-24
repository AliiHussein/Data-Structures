#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; // pointer of type (struct Node) named next
};

int isEmpty(struct Node* list){
    return (list == NULL);
}

// Use pointer to pointer if you are going to change the head
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

void display(struct Node* head){
    if(isEmpty(head)){
        printf("List is Empty\n");
    }
    else{
        struct Node* temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int count(struct Node* head){
    struct Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void main(){
    struct Node * Head = NULL; // created an Empty LL
    
    int newElement;
    int elemet;

    int options = 0;
    while(options != 1){
        printf("\n");
        printf("List: "); 
        display(Head);
        printf("Enter an option: ");
        scanf("%d", &options);
        switch (options)
        {
        case 1: break;
        case 2: printf("Enter new element to insert first: "); scanf("%d", &newElement); insertFirst(&Head,newElement); break;
        case 3: printf("count: %d\n", count(Head)); break;
        default: options = 1; break;
        }
    }

}