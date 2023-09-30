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

int isEmpty(struct Queue * q){
    return (q->front == NULL);
}

void enqueue(struct Queue * q, int element){
    // 1. create a new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    // 2. fill its data
    newnode->data = element;
    // 3. Assign it next
    newnode->next = NULL;
    // 4. Assign top & rear
    if(isEmpty(q)){
        q->front = newnode;
    }
    else{
        q->rear->next = newnode;
    }
    
    q->rear = newnode;
}

int dequeue(struct Queue * q){

    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return -1;
    }
    // 0. Save the value to return later
    int value = q->front->data;
    // 1. Create a delNode pointer
    struct Node* delNode = q->front;
    // 2. move the front one step
    q->front = q->front->next;
    // 3. delete the node
    free(delNode);

    return value;
}

void display(struct Queue * q){
    struct Node* temp = q->front;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int count(struct Queue * q){
    struct Node* temp = q->front;

    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int isFound(struct Queue * q, int key){
    struct Node* temp = q->front;

    while(temp != NULL){
        if(temp->data == key){
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

int Front(struct Queue * q){
    return q->front->data;
}

int Rear(struct Queue * q){
    return q->rear->data;
}

void clear(struct Queue * q){
    while(isEmpty(q) == 0){
        dequeue(q);
    }
}

void main(){
    struct Queue *q1 = (struct Queue*)malloc(sizeof(struct Queue)); // creating an empty queue
    q1->front = NULL;
    q1->rear = NULL;

    int elemet;

    int options = 0;
    while(options != 1){
        printf("\n");
        printf("Queue: "); 
        display(q1);
        printf("Enter an option: ");
        scanf("%d", &options);
        switch (options)
        {
        case 1: break;
        case 2: printf("Enqueue: "); scanf("%d", &elemet); enqueue(q1, elemet); break;
        case 3: printf("Dequeue: %d\n", dequeue(q1)); break;
        case 4: printf("Count: %d\n", count(q1)); break;
        case 5: printf("Front: %d\n", Front(q1)); break;
        case 6: printf("Rear: %d\n", Rear(q1)); break;
        case 7: printf("Search: "); scanf("%d", &elemet); printf("Found?: %d\n", isFound(q1, elemet)); break;
        case 8: printf("Clearing the Queue\n"); clear(q1); break;
        default: options = 1; break;
        }
    }
    
}