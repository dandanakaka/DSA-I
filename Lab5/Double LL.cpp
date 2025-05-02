//Program to implement listADT using doubly linked lists in C++
#include <iostream>
#include <cstdlib>
using namespace std;

class list{
private:
    struct node{
        int data;
        node *next;
        node *prev;
    };
    node *head;
    node *tail;
public:
    list(){head=tail=NULL;}
    bool insertbeg(int);
    bool insertend(int);
    bool insertpos(int,int);
    int deletebeg();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();
};

int main(){
    int choice;
    class list obj;
    while(true){
        cout<<"1:Insert Beginning\n2:Insert End\n3:Insert Position\n4:Delete Beginning\n5:Delete End\n6:Delete Position\n7:Search\n8:Display\n9:Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        if (choice==1){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            obj.insertbeg(value);
        }
        else if (choice==2){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            obj.insertend(value);
        }
        else if (choice==3){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            int index;
            cout<<"Enter Index: ";
            cin>>index;
            obj.insertpos(value,index);
        }
        else if (choice==4){
            obj.deletebeg();
        }
        else if (choice==5){
            obj.deleteend();
        }
        else if (choice==6){
            int index;
            cout<<"Enter Index: ";
            cin>>index;
            obj.deletepos(index);
        }
        else if (choice==7){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            obj.search(value);
        }
        else if (choice==8){
            obj.display();
        }
        else if(choice==9){
            break;
        }  
    }
    cout<<"Program Exited"<<endl;
    return 0;
}

// Function to display list in forward and reverse
void list::display(){
    if(head==NULL){
        cout<<"List Empty\n";
        return;
    }
    cout<<"List:\n";
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"Reverse List:\n";
    temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}


//Function to insert value at beginning of list
bool list::insertbeg(int num){
    node *newnode=(node*)malloc(sizeof(node));
    if (!newnode) return false;

    newnode->data=num;
    newnode->prev=NULL;
    if (head==NULL){
        newnode->next=NULL;
        tail=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
    }
    head=newnode;
    return true;
}

//Function to insert value at end of list
bool list::insertend(int num){
    if (head==NULL){
        return insertbeg(num);
    }
    node *newnode=(node*)malloc(sizeof(node));
    if (!newnode) return false;
    newnode->data=num;
    newnode->next=NULL;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    return true;
}

//Function to insert value at an index of list
bool list::insertpos(int num,int index){
    if (index<0){
        cout<<"Invalid Index\n";
        return false;
    }
    if (index==0){return insertbeg(num);}

    node *temp=head;
    for(int i=0;i<index-1;i++){
        if(temp==NULL){
            cout<<"Index out of range\n";
            return false;
        }
        temp=temp->next;
    }
    if(temp==tail){return insertend(num);}
    node *temp2=temp->next;
    node *newnode=(node*)malloc(sizeof(node));
    if (!newnode) return false;
    newnode->data=num;
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=temp2;
    temp2->prev=newnode;
    return true;
}

// Function to delete first element from list
int list::deletebeg(){
    if (head==NULL){
        cout<<"List is Empty\n";
        return -1;
    }
    int value=head->data;
    if (head==tail){
        free(head);
        head=tail=NULL;
        return value;
    }
    node *temp=head;
    if (head!=tail){
        head=head->next;
        head->prev=NULL;
    }
    free(temp);
    return value;
}
// Function to delete last element from list
int list::deleteend(){
    if (head==tail){return deletebeg();}
    int value=tail->data;
    node *temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
    return value;
}

// Function to delete element at given index from list
int list::deletepos(int index){
    if (index<0){
        cout<<"Invalid Index\n";
        return -1;
    }
    if (head==NULL){
        cout<<"List is Empty\n";
        return -1;
    }
    if(index==0){return deletebeg();}
    node *temp=head;
    for (int i=0;i<index;i++){
        if (temp==NULL){
            cout<<"Index out of range\n";
            return -1;
        }
        temp=temp->next;
    }
    if(temp->next==NULL){return deleteend();}
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    int value=temp->data;
    free(temp);
    return value;
}

// Function to search for specific element and return index
int list::search(int num){
    if (head==NULL){
        cout<<"Empty List\n";
        return -1;
    }
    int i=0;
    node *temp=head;
    while (temp){
        if (temp->data==num){
            cout<<"Found at index "<< i <<endl;
            return i;
        }
        temp=temp->next;
        i++;
    }
    cout<<"Number Not Found "<<endl;
    return -1;
}
