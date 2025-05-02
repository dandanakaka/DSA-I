//Program to implement listADT in C++
#include <iostream>
#include <cstdlib>
using namespace std;

class list{
private:
    struct node{
        int data;
        struct node *next;
    };
    struct node *head;
    node *gethead(){return head;}
public:
    list(){head=NULL;}
    bool insertasc(int);
    void display();
    void merge(list &,list &);
};

// Insert value in ascending order
bool list::insertasc(int num){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    if (head==NULL || head->data>num){
        newnode->next=head;
        head=newnode;
        return 1;
    }
    newnode->next=NULL;
    node *temp=head;
    while (temp->next!=NULL && temp->next->data<num){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return 1;
}

// Display list
void list::display(){
    if (head==NULL){
        cout<<"Empty List\n";
        return;
    }
    node *temp=head;
    cout<<"List:\n";
    while (temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//Merging 2 Lists
void list::merge(list &list2,list &list3){
    head=NULL;
    node *temp=list2.gethead();
    while (temp){
        insertasc(temp->data);
        temp=temp->next;
    }
    temp=list3.gethead();
    while (temp){
        insertasc(temp->data);
        temp=temp->next;
    }
}
