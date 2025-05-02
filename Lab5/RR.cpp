//Program to implement round robin scheduling algorithm using circular linked lists in c++
#include <iostream>
#include <cstdlib>
#include "cpu.h"
using namespace std;

int main(){
    int cpu_time;
    cout<<"Enter CPU processing time:";
    cin>>cpu_time;
    cpu obj(cpu_time);
    int choice;
    int time;
    while(true){
        cout<<"1:Insert Process\n2:Execute\n3:Display\n4:Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        if (choice==1){
            cout<<"Enter Process Time:";
            cin>>time;
            obj.inputprocess(time);
        }
        else if(choice==2){
            obj.execute();
        }
        else if(choice==3){
            obj.display();
        }
        else if(choice==4){
            break;
        }
    }
    cout<<"Program Exited\n";
}
