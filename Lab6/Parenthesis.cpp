//Program to check if parathentesis are balanced
#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

bool balanced(string s);

int main(){
    int choice;
    string s;
    cout<<"Enter Choice\n";
    cout<<"1: Check Balance\n2: Exit\n";
    cin>>choice;
    while (true){
        if (choice==1){
            cout<<"Enput String: ";
            cin>>s;
            if (balanced(s)) cout<<"Balanced\n";
            else{cout<<"Unbalanced\n";break;}
        }
        else if (choice==2){
            break;
        }
    }
}

//Function to check if parathentesis are balanced
bool balanced(string s){
    stack st;
    for (int i=0;i<s.length();i++){
        int ch=s[i];
        if (ch=='('){
            st.push(ch);
        }
        else if(ch==')' && st.peek()=='('){
            st.pop();
        }
    }
    if (st.peek()!=-1) return false;
    return true;
}
