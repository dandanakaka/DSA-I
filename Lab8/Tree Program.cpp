#include <iostream>
using namespace std;

class Tree{
private:
    struct node{
        char data;
        node *left;
        node *right;
    };
    node *root;

    node* insert(node* root, char data) {
        if (root == nullptr) {
            root = new node{data, nullptr, nullptr};
            return root;
        }
        char choice;
        cout << "Insert " << data << " to (l)eft or (r)ight of " << root->data << "? ";
        cin >> choice;
        if (choice == 'L' || choice == 'l')
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right,data);
        return root;
    }
    void preorder(node* root) {
        if (root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void postorder(node* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    bool search(node* root,char key){
        if (!root) return false;
        if (root->data==key) return true;
        return search(root->left,key) || search(root->right,key);

    }
public:
    Tree() { root = nullptr; }

    void insert(char data) { root = insert(root, data); }
    
    void displayPreorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    void search(char key){
        if (search(root, key))
            cout << "Element '" << key << "' found in the tree.\n";
        else
            cout << "Element '" << key << "' not found in the tree.\n";
    }
};

int main() {
    Tree tree;
    char choice, value;

    do {
        cout << "\nBinary Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter character to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case '2':
                tree.displayPreorder();
                break;
            case '3':
                tree.displayInorder();
                break;
            case '4':
                tree.displayPostorder();
                break;
            case '5':
                cout << "Enter character to search: ";
                cin >> value;
                tree.search(value);
                break;
            case '6':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != '6');

    return 0;
}
