#include <iostream>
#include "stack.h"
using namespace std;
int main(){
    string s;
    cout<<"Enter String: ";
    cin>>s;
    Linkedstack s1;
    int i=0;
    while(s[i]!='\0'){
        if (s[i]=='+'){
            s1.pop();
        }
        else{
            s1.push(s[i]);
        }
        i++;
    }
    s1.rdisplay();
}
