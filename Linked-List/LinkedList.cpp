#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Linkedlist{
public:
    Node* head;

    Linkedlist(){
        head = NULL;
    }

    bool isEmpty(){
        return (head == NULL);
    }

    void insertFirst(int element){
        // 1. Create a new node
        Node* newnode =new Node();
        // 2. Fill its data 
        newnode->data = element;
        //3. Assign its next node
        if(isEmpty()){
            newnode->next = NULL;
        }
        else{
            newnode->next = head;
        }
        // 4. Make the head points to it
        head = newnode;
    }

    void insertBefore(int element, int newElement){
        // 0. If it is empty then insert first
        if(isEmpty()){
            insertFirst(newElement);
            return;
        }

        if(isFound(element)){
            // 1. Create a new node
            Node* newnode =new Node();
            // 2. Fill its data
            newnode->data = newElement;

            Node* temp = head;

            while(temp != NULL && temp->next->data != element){
                temp = temp->next;
            }
            
            // 3. Assign its next to the next node
            newnode->next = temp->next;
            // 4. Make the current node points to it
            temp->next = newnode;
        }
        else{
            cout << "Item is not found!\n";
        }
    }

    void append(int element){
        // 0. If it is empty then insert first
        if(isEmpty()){
            insertFirst(element);
            return;
        }

        // 1. Create a new node
        Node* newnode =new Node();
        // 2. Fill its data
        newnode->data = element;

        Node* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        // 3. Assign its next to NULL
        newnode->next = NULL;
        // 4. Make the current node points to it
        temp->next = newnode;
    }

    void Delete(int element){
        // 0. If it is empty then return
        if(isEmpty()){
            cout << "List is empty" << endl;
            return;
        }

        if(isFound(element)){
            if(head-> data == element){
            Node* delNode = head;
            head = head->next;
            delete delNode;
            }
            else{
                Node* prev = NULL;
                Node* delNode = head;
                while(delNode->data != element){
                    prev = delNode;
                    delNode = delNode->next;
                }
                prev->next = delNode->next;
                delete delNode;
            }
        }
        else{
            cout << "Element is not found!" << endl;
        }
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int count(){
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isFound(int key){
        Node* temp = head;
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

    Linkedlist l1;
    int newElement;
    int elemet;

    int options = 0;
    while(options != 1){
        cout << "Enter an option: ";
        cin >> options;
        switch (options)
        {
        case 1: break;
        case 2: if(l1.isEmpty()){cout << "Linked list is Empty" << endl;} else{cout << "Linked list is not Empty" << endl;} break;
        case 3: cout << "Enter new element to insert first: "; cin >> newElement; l1.insertFirst(newElement); break;
        case 4: cout << "Linked List: "; l1.display(); break; 
        case 5: cout << "Count: " << l1.count() << endl; break;
        case 6: cout << "Enter element to search for: "; cin >> newElement; cout << l1.isFound(newElement) << endl; break;
        case 7: cout << "Enter element to insert before: "; cin >> elemet; cout << "Enter element to insert: "; cin >> newElement; l1.insertBefore(elemet, newElement); break;
        case 8: cout << "Enter new element to append: "; cin >> newElement; l1.append(newElement); break;
        case 9: cout << "Enter element to delete: "; cin >> elemet; l1.Delete(elemet); break;
        default: break;
        }
    }
    return 0;
}