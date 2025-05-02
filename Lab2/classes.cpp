#include <iostream>
using namespace std;

class Shapes {
public:
    int l,b,h;
    int cube(int l) {
        return 6 * (l * l);
    }

    int cuboid(int l, int b, int h) {
        return 2 * ((l * b) + (l * h) + (b * h));
    }

    int rectangle(int l, int b) {
        return l * b;
    }

    int square(int l) {
        return l * l;
    }
};

int main() {
    Shapes shape;
    char choice;
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "a) Square\n";
        cout << "b) Cube\n";
        cout << "c) Rectangle\n";
        cout << "d) Cuboid\n";
        cout << "e) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 'e') {
            break;
        }

        if (choice == 'a') {
            int side;
            cout << "Enter side length of the square: ";
            cin >> side;
            cout << "Area of the square: " << shape.square(side) << endl;
        }
        else if (choice == 'b') {
            int side;
            cout << "Enter side length of the cube: ";
            cin >> side;
            cout << "Surface area of the cube: " << shape.cube(side) << endl;
        }
        else if (choice == 'c') {
            int length, breadth;
            cout << "Enter length and breadth of the rectangle: ";
            cin >> length >> breadth;
            cout << "Area of the rectangle: " << shape.rectangle(length, breadth) << endl;
        }
        else if (choice == 'd') {
            int length, breadth, height;
            cout << "Enter length, breadth, and height of the cuboid: ";
            cin >> length >> breadth >> height;
            cout << "Surface area of the cuboid: " << shape.cuboid(length, breadth, height) << endl;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
