#include <iostream>
using namespace std;


class Queue {
private:
    struct node{
        int data;
        node *next;
    };
    node *front;
    node *rear;
public:
    Queue(){front=rear=NULL;}

    bool isFull();
    bool isEmpty();
    void enqueue(int value);
    int dequeue();
    int peek();
};

int main(){
    Queue obj;
    int choice;
    while(true){
        cout<<"1:Insert\n2:Delete\n3:Peek\n4:Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        if (choice==1){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            obj.enqueue(value);
        }
        else if (choice==2){
            obj.dequeue();
        }
        else if (choice==3){
            obj.peek();
        }
        else if (choice==4){
            break;
        }
    }
    return 0;
}


bool Queue::isEmpty(){
    return (front==NULL);
}

void Queue::enqueue(int value){
    node *temp=new node;
    temp->data=value;
    temp->next=NULL;
    if (isEmpty()){
        front=temp;
        rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

int Queue::dequeue(){
    if (isEmpty()){
        cout<<"Queue is EMPTY! Cannot dequeue.\n";
        return;
    }
    node *temp=front;
    int value=front->data;
    front=front->next;
    delete temp;
    return value;
}

int Queue::peek(){
    if (isEmpty()){
        cout<<"Queue is EMPTY! No front element.\n";
        return;
    }
    cout<<"Front Element: "<<front->data<<endl;
    return front->data;
}
