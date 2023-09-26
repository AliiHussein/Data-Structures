#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Stack{
public:
    Node* top;

    Stack(){
        top = NULL;
    }

    bool isEmpty(){
        return (top == NULL);
    }

    bool isFull()
	{
        /*
            To check if the stack is full I create a new node and if its address is NULL then the heap is full
        */
		Node* ptr = new Node();
		if (ptr == NULL)
			cout << "The Stack is Full , cannot add more items \n";
	}

    void push(int element){
        // 1. create the new node
        Node* newnode = new Node;
        // 2. fill the data
        newnode->data = element;
        // 3. Assign it next
        newnode->next = top;
        // 4. Assign the top to the new node
        top = newnode;
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return -1;
        }

        int element = top->data;

        Node* delNode = top;
        top = top->next;

        delete delNode;

        return element;
    }

    int peek(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return (top->data);
    }

    void display(){
        Node* temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int count(){
        Node* temp = top;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isFound(int key){
        Node* temp = top;
        while(temp != NULL){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

};


int main(){
    Stack s1;
    
    int element;

    int options = 0;
    while(options != 1){
        cout << endl << "Stack: "; 
        s1.display();
        cout << "Enter an option: ";
        cin >> options;
        switch (options)
        {
        case 1: break;
        case 2: cout << "Push: "; cin >> element; s1.push(element); break;
        case 3: cout << "Count: " << s1.count() << endl; break;
        case 4: cout << "Enter element to search for: "; cin >> element; cout << s1.isFound(element) << endl; break;
        case 5: cout << "Peek: "; cout << s1.peek() << endl; break;
        case 6: cout << "Pop: "; cout << s1.pop() << endl; break;
        default: options = 1; break;
        }
    }
    return 0;
}