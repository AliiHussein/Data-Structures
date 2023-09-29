#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
};

int isEmpty(struct Node * front){
    return (front == NULL);
}

void enqueue(struct Node ** front, struct Node ** rear, int element){
    // 1. create a new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    // 2. fill its data
    newnode->data = element;
    // 3. Assign it next
    newnode->next = NULL;
    // 4. Assign top & rear
    if(isEmpty(*front)){
        *front = newnode;
    }
    else{
        (*rear)->next = newnode;
    }
    
    *rear = newnode;
}

int dequeue(struct Node ** front, int element){

    if(isEmpty(*front)){
        printf("Queue is Empty!\n");
        return -1;
    }
    // 0. Save the value to return later
    int value = (*front)->data;
    // 1. Create a delNode pointer
    struct Node* delNode = *front;
    // 2. move the front one step
    *front = (*front)->next;
    // 3. delete the node
    free(delNode);

    return value;
}

void display(struct Node * front){
    struct Node* temp = front;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main(){
    struct Queue q1 = {NULL, NULL}; // creating an empty queue

    int elemet;

    int options = 0;
    while(options != 1){
        printf("\n");
        printf("Queue: "); 
        display(q1.front);
        printf("Enter an option: ");
        scanf("%d", &options);
        switch (options)
        {
        case 1: break;
        case 2: printf("Enqueue: "); scanf("%d", &elemet); enqueue(&(q1.front),&(q1.rear), elemet); break;
        case 3: printf("Dequeue: %d\n", dequeue(&(q1.front), elemet)); break;
        default: options = 1; break;
        }
    }
    
}