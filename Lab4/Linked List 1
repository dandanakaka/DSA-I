//Program to implement listADT in C++
#include <iostream>
#include <cstdlib>
using namespace std;

class list{
private:
    struct node{
        int data;
        node *next;
    };
    node *head;
public:
    list(){head=NULL;}
    bool insertbeg(int);
    bool insertend(int);
    bool insertpos(int,int);
    int deletebeg();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();
    void rdisplayHelper(node*);
    void rdisplay();
    void rev();
};


int main(){
    int choice;
    class list list1;
    while(true){
        cout<<"1:Insert Beginning\n2:Insert End\n3:Insert Position\n4:Delete Beginning\n5:Delete End\n6:Delete Position\n7:Search\n8:Display\n9:Rdisplay\n10:reverse\n0:Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        if (choice==1){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            list1.insertbeg(value);
        }
        else if (choice==2){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            list1.insertend(value);
        }
        else if (choice==3){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            int index;
            cout<<"Enter Index: ";
            cin>>index;
            list1.insertpos(value,index);
        }
        else if (choice==4){
            list1.deletebeg();
        }
        else if (choice==5){
            list1.deleteend();
        }
        else if (choice==6){
            int index;
            cout<<"Enter Index: ";
            cin>>index;
            list1.deletepos(index);
        }
        else if (choice==7){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            list1.search(value);
        }
        else if (choice==8){
            list1.display();
        }
        else if (choice==9){
            list1.rdisplay();
        }
        else if (choice==10){
            list1.rev();
        }
        else if(choice==0){
            break;
        }  
    }
    cout<<"Program Exited"<<endl;
    return 0;
}
 //Function to insert value at beginning
bool list::insertbeg(int num){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    return 1;
}
//Function to display elements of list
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
//Function to insert value at end
bool list::insertend(int num){
    if (head==NULL){
        insertbeg(num);
        return 1;
    }
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    newnode->next=NULL;
    node *temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return 1;
}
//Function to insert value at specific index
bool list::insertpos(int num,int index){
    if (index==0){
        insertbeg(num);
        return 1;
    }
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    newnode->next=NULL;
    node *temp=head;
    for (int i=0;i<index-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return 1;
}
//Function to delete first element from list
int list::deletebeg(){
    if (head==NULL){
        cout<<"Empty List\n";
        return -1;
    }
    node *temp=head;
    head=head->next;
    int value=temp->data;
    free(temp);
    return value;
}
//Function to delete last element from list
int list::deleteend(){
    if (head==NULL){
        cout<<"Empty List\n";
        return -1;
    }
    if (head->next==NULL){
        int value=head->data;
        free(head);
        head=NULL;
        return value;
    }
    node *temp=head;
    while (temp->next->next!=NULL){
        temp=temp->next;
    }
    node *del=temp->next;
    int value=del->data;
    free(del);
    temp->next=NULL;
    return value;
}
//Function to delete element at given index from list
int list::deletepos(int index){
    if (head==NULL){
        cout<<"Empty List\n";
        return -1;
    }
    if (head->next==NULL){
        int value=head->data;
        free(head);
        head=NULL;
        return value;
    }
    node *temp=head;
    for (int i=0;i<index-1;i++){
        if (temp->next==NULL){
            cout<<"Index Out of Range\n";
            return -1;
        }
        temp=temp->next;
    }
    int value=temp->next->data;
    temp->next=temp->next->next;
    return value;
}
//Function to search for specific element and return index
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

//Function to display elements of list in reverse
void list::rdisplayHelper(node* temp){
    if (temp==NULL) return;
    rdisplayHelper(temp->next);
    cout<<temp->data<<" ";
}
void list::rdisplay(){
    if (head==NULL){
        cout<<"Empty List\n";
        return;
    }
    rdisplayHelper(head);
    cout<<endl;
}

//Fucntion to reverse the order of elements in list
void list::rev(){
    node* temp=NULL;
    node* temp2=NULL;
    while (head!=NULL){
        temp2=head->next;
        head->next=temp;
        temp=head;
        head=temp2;
    }
    head=temp;
    
}
