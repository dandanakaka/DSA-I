//Program to implement Priority Queue using max heap
#include <iostream>
using namespace std;
#define SIZE 100

class MaxHeap{
private:
    int arr[SIZE];
    int size;

    void up(int index){
        while (index>0){
            int parent = (index-1)/2;
            if (arr[index]>arr[parent]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else{
                break;
            }
        }
    }

    void down(int index){
        while (true){
            int left= 2*index+1;
            int right = 2*index+2;
            int largest =index;
            if (left<size && arr[left]>arr[largest]){
                largest = left;
            }
            if (right<size && arr[right]>arr[largest]){
                largest = right;
            }
            if (largest!=index){
                swap(arr[index],arr[largest]);
                index=largest;
            }
            else{
                break;
            }
        }
    }
public:
    MaxHeap(){size = 0;}
    void insert(int );
    void display();
    int search(int );
    int deleteval(int );
    void sort();
    int extractmax();
    
};


int main(){
    MaxHeap obj;
    int choice;
    while(true){
        cout<<"1:Insert\n2:Display\n3:Search\n4:delete\n5:Sort\n6:Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        if (choice==1){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            obj.insert(value);
        }
        else if (choice==2){
            obj.display();
        }
        else if (choice==3){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            obj.search(value);
        }
        else if (choice==4){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            obj.deleteval(value);
        }
        else if (choice==5){
            obj.sort();
        }
        else if (choice==6){
            break;
        }
    }
}


//Function to insert value to heap
void MaxHeap::insert(int value){
    if (size == SIZE) {
        cout << "Heap is Full!\n";
        return;
    }
    arr[size] = value;
    up(size);
    size++;
}
//Function to display heap
void MaxHeap::display() {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return;
    }
    cout << "Heap elements: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
//Function to search element
int MaxHeap::search(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            cout << "Element found at index " << i << endl;
            return i;
        }
    }
    cout << "Element not found\n";
    return -1;
}
//Function to delete root element
int MaxHeap::extractmax(){
    if (size == 0) {
        cout<<"Heap is Empty\n";
        return -1;
    }
    int max = arr[0];
    arr[0] = arr[size-1];
    size--;
    down(0);
    return max;
}
//Function to sort heap
void MaxHeap::sort() {
    int original = size;
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        size--;
        down(0);
    }
    size = original;
}
//Function to delete specefic element
int MaxHeap::deleteval(int value){
    int index = search(value);
    if (index == -1) {
        return 0;
    }
    arr[index] = arr[size-1];
    size--;
    down(index);
    return 1;
}
