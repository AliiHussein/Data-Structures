#include <iostream>
using namespace std;

#define MAX_SIZE  4

template<class data>

class Stack
{
private:
    int top;
    data arr[MAX_SIZE];
public:
    Stack(){
        top = -1;
    }

    void push(data element){
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

    void pop(data&Element){
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
    Stack<char>s;
    char t = s.Top();
    cout << t << endl;

    s.push('A');
    s.push('B');
    s.push('c');

    t = s.Top();
    cout << t << endl;

    s.pop();

    t = s.Top();
    cout << t << endl;

    return 0;
}