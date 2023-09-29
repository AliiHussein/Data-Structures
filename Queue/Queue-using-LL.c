#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

void main(){
    struct Node* Front = NULL;

    int elemet;

    int options = 0;
    while(options != 1){
        printf("\n");
        printf("Queue: "); 
        display(Front);
        printf("Enter an option: ");
        scanf("%d", &options);
        switch (options)
        {
        case 1: break;
        case 2: printf("Enqueue: "); scanf("%d", &elemet); push(&Front, elemet); break;
        default: options = 1; break;
        }
    }
    
}