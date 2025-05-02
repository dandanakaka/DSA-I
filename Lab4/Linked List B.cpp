//Program to implement list ADT in c++
#include <iostream>
#include <cstdlib>
#include "LinkedB.h"
using namespace std;


int main(){
    int Choice;
    class list list1;
    class list list2;
    class list list3;
    while(true){
        cout<<"1:Insert into list 1\n2:Insert into list 2\n3:Display\n4:Merge\n5:Exit\n";
        cout<<"Enter Choice: ";
        cin>>Choice;
        if (Choice==1){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            list2.insertasc(value);
        }
        else if (Choice==2){
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            list3.insertasc(value);
        }
        else if (Choice==3){
            list1.display();
        }
        else if (Choice==4){
            list1.merge(list2,list3);
        }
        else if (Choice==5){
            break;
        }
    }
    return 0;
}
