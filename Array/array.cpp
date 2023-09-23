#include <iostream>
using namespace std;

class Array{
private:
    int size;
    int *items;
    int length;
public:

    Array(int arrSize){
        size = arrSize;
        items = new int[arrSize];
        length = 0;
    }

    void fill(){
        cout << "Enter the length to fill: ";
        int len;
        cin >> len;
        if(len > size){
            cout << "Choosen length is greater than the size of the array" << endl;
        }
        else{
            for(int i = 0; i < len; i++){
                cout << "Enter item " << i << ": ";
                cin >> items[i];
                length++;
            }
        }

    }

    void display(){
        cout << "array: ";
        for(int i = 0; i < length; i++){
            cout << items[i] << " ";
        }
        cout << endl;
    }

    int getLength(){
        return length;
    }
    int getSize(){
        return size;
    }
    
};

int main(){

    int arrsize;
    cout << "Enter array size: ";
    cin >> arrsize;
    Array a1(arrsize);
    a1.fill();
    int options = 0;
    while(options != 1){
        cin >> options;
        switch (options)
        {
        case 1: break;
        case 2: a1.display(); break;
        case 3: cout << "Array length is: " << a1.getLength() << endl; break;
        case 4: cout << "Array size is: " << a1.getSize() << endl; break;
        default: break;
        }
    }

    return 0;
}