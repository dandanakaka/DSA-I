//Function and Declarations to implement stack using Array
#include <iostream>
using namespace std;

class stack{
private:
    char array[5];
    int cur;
public:
    stack(){
        cur=-1;
    }
    char pop();
    bool push(char);
    char peek();
};


int main() {
    stack s;
    int choice;
    char value;

    while (true) {
        cout << "\n1: Push\n2: Pop\n3: Peek\n0: Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Value: ";
            cin >> value;
            s.push(value);
        } 
        else if (choice == 2) {
            cout << "Popped element: " << s.pop() << endl;
        } 
        else if (choice == 3) {
            cout << "Top element: " << s.peek() << endl;
        }
        else if (choice == 0) {
            break;
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }
    cout << "Program Exited.\n";
    return 0;
}


//Function to insert value to top of stack
bool stack::push(char value){
    if (cur==4){
        cout<<"Stack Overflow\n";
        return 0;
    }
    array[++cur]=value;
    return 1;
}

//Function to remove value from top of stack
char stack::pop(){
    if (cur==-1){
       cout<<"Stack Underflow\n";
        return -1;
    }
    char temp=array[cur];
    cur--;
    return temp;
}

//Fuccntion to return value from top of stack
char stack::peek(){
    if (cur==-1){
        cout<<"Stack Underflow\n";
         return -1;
    }
    return array[cur];
}
