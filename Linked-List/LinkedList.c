#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; // pointer of type (struct Node) named next
};

int isEmpty(struct Node* list){
    return (list == NULL);
}

int isFound(struct Node* head, int key){
    struct Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
                return 1;
            }
            temp = temp->next;
        }
    return 0;
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

void insertBefore(struct Node** head, int element, int newElement){
    if(isEmpty(*head)){
        insertFirst(head, newElement);
        return;
    }

    if(isFound(*head, element)){
        // 1. Create a new node
        struct Node* newnode =(struct Node*)malloc(sizeof(struct Node));
        // 2. Fill its data
        newnode->data = newElement;

        if((*head)->data == element){
            insertFirst(head, newElement);
            return;
        }

        struct Node* temp = *head;

        while(temp != NULL && temp->next->data != element){
            temp = temp->next;
        }
        
        // 3. Assign its next to the next node
        newnode->next = temp->next;
        // 4. Make the current node points to it
        temp->next = newnode;
    }
    else{
        printf("Item is not found!\n");
    }
    
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
        case 4: printf("Enter element to insert before: "); scanf("%d", &elemet); printf("Enter element to insert: "); scanf("%d", &newElement); insertBefore(&Head, elemet, newElement); break;
        case 5: printf("Enter element to search for: "); scanf("%d", &elemet); printf("%d\n", isFound(Head, elemet)); break;
        default: options = 1; break;
        }
    }

}