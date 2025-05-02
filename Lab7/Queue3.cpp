//Program to implement queue using array
#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull();
    bool isEmpty();
    void enqueue(int value);
    void dequeue();
    void peek();
    void display();
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                q.display();
                break;

            case 2:
                q.dequeue();
                q.display();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}



// Function to check if the queue is full
bool Queue::isFull() {
    return (rear == SIZE - 1);
}

// Function to check if the queue is empty
bool Queue::isEmpty() {
    return (front == -1 || front > rear);
}

// Function to Enqueue element
void Queue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is FULL! Cannot enqueue " << value << endl;
        return;
    }
    if (front == -1) front = 0;
    arr[++rear] = value;
    cout << "Enqueued: " << value << endl;
}

// Function to Dequeue element
void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Cannot dequeue.\n";
        return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    front++;
}

// Function to return front element
void Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! No front element.\n";
        return;
    }
    cout << "Front Element: " << arr[front] << endl;
}

// Display queue elements
void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!\n";
        return;
    }
    cout << "Queue Elements: ";
    for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";
    cout << endl;
}
