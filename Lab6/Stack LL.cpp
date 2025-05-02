//Program to implement stack using linked list
#include <iostream>
#include "stack.h"
using namespace std;

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
        } else if (choice == 2) {
            cout << "Popped element: " << s.pop() << endl;
        } else if (choice == 3) {
            cout << "Top element: " << s.peek() << endl;
        } else if (choice == 0) {
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    cout << "Program Exited.\n";
    return 0;
}
