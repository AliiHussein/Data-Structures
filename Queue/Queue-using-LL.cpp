#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Queue{
public:
    Node* front;
    Node* rear;

    Queue(){
        front = NULL;
        rear = NULL;
    }

    bool isEmpty(){
        return (front == NULL);
    }

    void enqueue(int element){
        // 1. create a new node
        Node* newnode = new Node;
        // 2. fill its data
        newnode->data = element;
        // 3. Assign it next
        newnode->next = NULL;
        // 4. Assign top & rear
        if(isEmpty()){
            front = newnode;
        }
        else{
            rear->next = newnode;
        }
        
        rear = newnode;
    }

    int dequeue(){

        if(isEmpty()){
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        // 0. Save the value to return later
        int value = front->data;
        // 1. Create a delNode pointer
        Node* delNode = front;
        // 2. move the front one step
        front = front->next;
        // 3. delete the node
        delete delNode;

        return value;
    }

    void display(){
        Node* temp = front;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int count(){
        Node* temp = front;

        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isFound(int key){
        Node* temp = front;

        while(temp != NULL){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    int Front(){
        return (front->data);
    }

    int Rear(){
        return (rear->data);
    }

    void clear(){
        while(isEmpty() == 0){
            dequeue();
        }
    }

};

int main(){

    Queue q1;

    int element;

    int options = 0;
    while(options != 1){
        cout << endl << "Queue: "; 
        q1.display();
        cout << "Enter an option: ";
        cin >> options;
        switch (options)
        {
        case 1: break;
        case 2: cout << "Enqueue: "; cin >> element; q1.enqueue(element); break;
        case 3: cout << "Dequeue: " << q1.dequeue() << endl; break;
        case 4: cout << "Front: " << q1.Front() << endl; break;
        case 5: cout << "Rear: " << q1.Rear() << endl; break;
        case 6: cout << "Count: " << q1.count() << endl; break;
        case 7: cout << "Search: "; cin >> element; cout << "Found? " << q1.isFound(element) << endl; break;
        case 8: cout << "Clearing the Queue" << endl; q1.clear(); break;
        default: options = 1; break;
        }
    }

    return 0;
}
