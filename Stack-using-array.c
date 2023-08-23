#include <stdio.h>

#define MAX_SIZE 4

int top = -1;

void push(int * stack, int element){
    stack[++top] = element;
}

int pop(int * stack){
    return stack[top--];
}

void main(){
    int Stack[MAX_SIZE];
    
    push(Stack, 1);
    push(Stack, 2);
    push(Stack, 3);

    printf("%d\n", pop(Stack));
    printf("%d\n", pop(Stack));
    printf("%d\n", pop(Stack));

}