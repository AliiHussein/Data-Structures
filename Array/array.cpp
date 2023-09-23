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

    int search(int key){
        for(int i = 0; i < length; i++){
            if(key == items[i]){
                return i;
            }
        }
        cout << "element not Found\n";
        return -1;
    }

    void append(int element){
        if(length < size){
            items[length++] = element;
        }
        else{
            cout << "Cannot append, Array is full\n";
        }
    }

    void insert(int index, int element){
        if(index >= 0 && index < length){
            if(length < size){
                // shifting right
                for(int i = length; i > index; i--){
                    items[i] = items[i-1];
                }
                items[index] = element;
                length++;
            }
            else{
                cout << "Cannot insert, Array is full\n";
            }
        }
        else{
            cout << "Index is out of bound\n";
        }
        
    }

    void Delete(int index){
        if(index >= 0 && index < length){
            if(index == (length-1)){
                length--;
                return;
            }

            for(int i = index; i < (length-1); i++){
                items[i] = items[i+1];
            }
            length--;
        }
        else{
            cout << "Index is out of bound\n";
        }
    }

    void Enlarge(int newSize){

        if(newSize <= size){
            cout << "The new size is not more than the current size\n";
            return;
        }

        int *old = items;
        size = newSize;
        items = new int[size];

        for(int i = 0; i < length; i++){
            items[i] = old[i];
        }
        delete [] old;
    }

    void merge(Array a2){
        int *old = items;
        size = size + a2.getSize();
        items = new int[size];

        int i;
        for(i = 0; i < length; i++){
            items[i] = old[i];
        }
        delete [] old;

        for(int j = 0; j < a2.getLength(); j++){
            items[i++] = a2.items[j];
            length++;
        }

    }
    
};

int main(){

    int arrsize;
    int element;
    int index;
    cout << "Enter array size: ";
    cin >> arrsize;
    Array a1(arrsize);
    a1.fill();

    cout << "Enter array size: ";
    cin >> arrsize;
    Array a2(arrsize);
    a2.fill();

    int options = 0;
    while(options != 1){
        cout << "Enter an option: ";
        cin >> options;
        switch (options)
        {
        case 1: break;
        case 2: a1.display(); break;
        case 3: cout << "Array length is: " << a1.getLength() << endl; break;
        case 4: cout << "Array size is: " << a1.getSize() << endl; break;
        case 5: cout << "Enter the element to search for: "; cin >> element; cout << "Key: " << a1.search(element) << endl; break;
        case 6: cout << "Enter element to append: "; cin >> element;  a1.append(element); break;
        case 7: cout << "Enter element to insert: "; cin >> element; cout << "Enter index: "; cin >> index;  a1.insert(index, element); break;
        case 8: cout << "Enter Index to delete: "; cin >> index;  a1.Delete(index); break;
        case 9: cout << "Enter new Size: "; cin >> arrsize;  a1.Enlarge(arrsize); break;
        case 10: cout << "Merge Arrays: " << endl; a1.merge(a2); break;
        default: break;
        }
    }

    return 0;
}