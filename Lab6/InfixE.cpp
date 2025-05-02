//Program to implement infix to postfix and postfix evaluation
#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int priority(char);
string getinfix();
string convert(string);
int evaluatePostfix(string);



int main(){
    int choice;
    string infix="";
    string postfix="";
    while (true){
        cout << "1: Get Infix\n2: Convert Infix to Postfix\n3: Evaluate Postfix\n4: Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1){
            infix= getinfix();
        }
        else if (choice == 2){
            if (infix.empty()){
                cout << "Infix is empty\n";
                continue;
            }
            postfix=convert(infix);
        }
        else if (choice == 3){
            if (postfix.empty()){
                cout << "postfix is empty\n";
                continue;
            }
            cout<<"Postfix Evaluation: ";
            cout << evaluatePostfix(postfix) << endl;
        }
        else if (choice == 4){
            break;
        }
        else{
            cout << "Invalid Choice\n";
        }
    }
    return 0;
}
//Function to get Infix Expression from user
string getinfix(){
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;
    return infix;
}
//Function to convert Infix to Postfix
string convert(string infix){
    string result;
    stack st;
    
    while (infix.length() > 0){
        char ch = infix[0];
        
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            result += ch;
            infix.erase(0, 1);
        }
        else if (ch == '('){
            infix.erase(0, 1);
            st.push('(');
        }
        else if (ch == ')'){
            infix.erase(0, 1);
            while (st.peek() != '(' && st.peek() != -1){
                result += st.peek();
                st.pop();
            }
            if (st.peek() == '(') {
                st.pop();
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '='){
            infix.erase(0, 1);
            if (ch == '^') {
                while (st.peek() != -1 && priority(st.peek()) > priority(ch)) {
                    result += st.peek();
                    st.pop();
                }
            }
            else {
                while (st.peek() != -1 && priority(st.peek()) >= priority(ch)) {
                    result += st.peek();
                    st.pop();
                }
            }
            st.push(ch);
        }
        else {
            infix.erase(0, 1);
        }
    }
    while (st.peek() != -1){
        if (st.peek() != '(') {
            result += st.peek();
        }
        st.pop();
    }
    
    cout << "Postfix Expression: " << result << endl;
    return result;
}
// Function to evaluate postfix expression
int evaluatePostfix(string postfix){
    stack st;
    for(int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if(ch >= '0' && ch <= '9') {
            st.push(ch - '0');
        }
        else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            int value;
            if (ch >= 'a' && ch <= 'z') value= (ch - 'a' + 1);
            else{value =(ch - 'A' + 1);}
            st.push(value);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '=') {
            int val1 = st.pop();
            int val2 = st.pop();
            switch(ch) {
                case '+': 
                    st.push(val2 + val1);
                    break;
                case '-': 
                    st.push(val2 - val1);
                    break;
                case '*': 
                    st.push(val2 * val1);
                    break;
                case '/': 
                    st.push(val2 / val1);
                    break;
                case '^': {
                    int result = 1;
                    for(int j = 0; j < val1; j++) {
                        result *= val2;
                    }
                    st.push(result);
                    break;
                }
                case '=':
                    st.push(val1);
                    break;
            }
        }
    }
    if(st.peek() != -1) {
        return st.pop();
    }
}

//Helper Function for convert
int priority(char c){
    if (c=='(' || c=='='){
        return 0;
    }
    else if (c=='+' || c=='-'){
        return 1;
    }
    else if (c=='*' || c=='/'){
        return 2;
    }
    else if (c=='^'){
        return 3;
    }
    return -1;
}
