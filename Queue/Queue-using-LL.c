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

int dequeue(struct Node ** front){

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

int count(struct Node * front){
    struct Node* temp = front;

    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int isFound(struct Node * front, int key){
    struct Node* temp = front;

    while(temp != NULL){
        if(temp->data == key){
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

int Front(struct Node* front){
    return front->data;
}

int Rear(struct Node* rear){
    return rear->data;
}

void clear(struct Node ** front){
    while(isEmpty(*front) == 0){
        dequeue(front);
    }
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
        case 3: printf("Dequeue: %d\n", dequeue(&(q1.front))); break;
        case 4: printf("Count: %d\n", count(q1.front)); break;
        case 5: printf("Front: %d\n", Front(q1.front)); break;
        case 6: printf("Rear: %d\n", Rear(q1.rear)); break;
        case 7: printf("Search: "); scanf("%d", &elemet); printf("Found?: %d", isFound(q1.front, elemet)); break;
        case 8: printf("Clearing the Queue\n"); clear(&(q1.front)); break;
        default: options = 1; break;
        }
    }
    
}