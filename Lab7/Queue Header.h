//Function and Declarations to implement stack using linked list
#include <iostream>
using namespace std;
class Linkedstack{
    private:
        struct node{
            char data;
            node *next;
        };
        node *head;
    public:
        Linkedstack(){head=NULL;}
        bool push(char);
        char pop();
        char peek();
        void display();
        void rdisplayHelper(node*);
        void rdisplay();
    };

//Function to insert value to top of stack
    bool Linkedstack::push(char num){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    return 1;
}

//Function to remove value from top of stack
char Linkedstack::pop(){
    if (head==NULL){
        // cout<<"Stack Underflow\n";
        return -1;
    }
    node *temp=head;
    head=head->next;
    char value=temp->data;
    free(temp);
    return value;
}

//Function to return value from top of stack
char Linkedstack::peek(){
    if (head==NULL){
        // cout<<"Stack Underflow\n";
        return -1;
    }
    return head->data;
}

//Function to display elements of stack
void Linkedstack::display(){
    if (head==NULL){
        cout<<"Empty Stack\n";
        return;
    }
    node *temp=head;
    while (temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


//Function to display elements of list in reverse
void Linkedstack::rdisplayHelper(node* temp){
    if (temp==NULL) return;
    rdisplayHelper(temp->next);
    cout<<temp->data<<" ";
}
void Linkedstack::rdisplay(){
    if (head==NULL){
        cout<<"Empty List\n";
        return;
    }
    rdisplayHelper(head);
    cout<<endl;
}
