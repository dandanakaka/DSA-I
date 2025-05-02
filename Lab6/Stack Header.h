//Function and Declarations to implement stack using linked list
#include <iostream>
using namespace std;
class stack{
    private:
        struct node{
            char data;
            node *next;
        };
        node *head;
    public:
        stack(){head=NULL;}
        bool push(char);
        char pop();
        char peek();
    };

//Function to insert value to top of stack
bool stack::push(char num){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    return 1;
}

//Function to remove value from top of stack
char stack::pop(){
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

//Fuccntion to return value from top of stack
char stack::peek(){
    if (head==NULL){
        // cout<<"Stack Underflow\n";
        return -1;
    }
    return head->data;
}
