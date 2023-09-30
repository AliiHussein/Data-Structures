#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Stack{
    struct Node* top;
};

int isEmpty(struct Node* top){
    return (top == NULL);
}

void push(struct Node** top, int element){
    // 1. create a new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    // 2. Fill its data
    newnode->data = element;
    // 3. Assign its next
    newnode->next = *top;
    // 4. Assign top to new node
    *top = newnode;

}

int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack is Empty!\n");
        return -1;
    }

    int value = (*top)->data;

    struct Node* delNode = (*top);

    (*top) = (*top)->next;

    free(delNode);

    return value;

}

void display(struct Node* top){
    struct Node* temp = top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

int count(struct Node* top){
    struct Node* temp = top;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int isFound(struct Node* top, int key){
    struct Node* temp = top;
    while(temp != NULL){
        if(temp->data == key){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int peek(struct Node* top){
    if(isEmpty(top)){
        printf("Stack is Empty!\n");
        return -1;
    }
    return (top->data);
}


void main(){

    struct Stack s1 = {NULL}; // creating an empty stack

    int elemet;

    int options = 0;
    while(options != 1){
        printf("\n");
        printf("Stack: "); 
        display(s1.top);
        printf("Enter an option: ");
        scanf("%d", &options);
        switch (options)
        {
        case 1: break;
        case 2: printf("Push: "); scanf("%d", &elemet); push(&(s1.top), elemet); break;
        case 3: printf("Pop: %d\n",pop(&(s1.top))); break;
        case 4: printf("Peek: %d\n",peek(s1.top)); break;
        case 5: printf("Count: %d\n",count(s1.top)); break;
        case 6: printf("Search: "); scanf("%d", &elemet); printf("is Found? : %d\n", isFound(s1.top, elemet)); break;
        default: options = 1; break;
        }
    }
}