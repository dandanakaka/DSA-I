//Program to implement circular queue using array
#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;
    int count;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isFull();
    bool isEmpty();
    void enqueue(int value);
    void dequeue();
    void peek();
    void display();
};

int main() {
    CircularQueue q;
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
bool CircularQueue::isFull() {
    return (count == SIZE);
}

// Function to check if the queue is empty
bool CircularQueue::isEmpty() {
    return (count == 0);
}

// Function to Enqueue element
void CircularQueue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is FULL! Cannot enqueue " << value << endl;
        return;
    }
    rear = (rear + 1) % SIZE;  // Wrap around
    arr[rear] = value;
    count++;
    if (front == -1) front = 0;  // Set front if inserting first element
    cout << "Enqueued: " << value << endl;
}

// Function to Dequeue element
void CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Cannot dequeue.\n";
        return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    front = (front + 1) % SIZE;
    count--;
    if (count == 0) front = rear = -1;
}

// Function to return front element
void CircularQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! No front element.\n";
        return;
    }
    cout << "Front Element: " << arr[front] << endl;
}

// Display queue elements
void CircularQueue::display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!\n";
        return;
    }
    cout << "Queue Elements: ";
    for (int i = 0; i < count; i++) {
        cout << arr[(front + i) % SIZE] << " ";
    }
    cout << endl;
}
