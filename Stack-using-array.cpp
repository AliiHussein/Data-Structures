#include <iostream>
using namespace std;

const int MAX_SIZE = 4;

class Stack
{
private:
    int top;
    int arr[MAX_SIZE];
public:
    Stack(){
        top = -1;
    }

    void push(int element){
        if(top == (MAX_SIZE - 1)){
            cout << "Array is full" << endl;
        }
        else{
            arr[++top] = element;
        } 
    }

    void pop(){
        if(top == -1){
            cout << "Array is Empty" << endl;
        }
        else{
            top--;
        } 
    }

    void pop(int&Element){
        if(top == -1){
            cout << "Array is Empty" << endl;
        }
        else{
            Element = arr[top];
            top--;
        } 
    }

    int Top(){
        if(top == -1){
            cout << "Array is Empty" << endl;
            return -1;
        }
        else{
            return arr[top];
        } 
    }

    bool isEmpty(){
        return top < 0;
    }

    void print(){
        for(int i = 0; i <= top ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    Stack s;
    int t = s.Top();
    cout << t << endl;

    s.push(1);
    s.push(2);
    s.push(3);

    t = s.Top();
    cout << t << endl;

    s.pop();

    t = s.Top();
    cout << t << endl;

    return 0;
}