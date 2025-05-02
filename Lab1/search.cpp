#include <iostream>
#include "sort.h"
using namespace std;

int linear(int l[],int len,int f){
    for (int i=0;i<len;i++){
        if (l[i]==f){
            return i;
        }    
    }
}

int binary(int l[],int s,int e,int f){
    if (s>e) return -1;
    int mid=s+(e-s)/2;
    if (l[mid]==f) return mid;
    else if (l[mid]>f) return binary(l,s,mid-1,f);
    else if (l[mid]<f) return binary(l,mid+1,e,f);
}

int main(){
    int list[10]={4,1,9,6,2,3,5,62,1,0};
    int len=10;
    int c=3;
    while (true){
        cout <<"Linear:1\nBianary:2\nExit:3\n";
        cout << "Enter choice: ";
        cin >>c;
        if (c==1){
            int l[10];
            for (int i=0;i<10;i++){
                l[i]=list[i];
            }
            int f;
            printlist(l,len);
            cout << "Enter number to find: ";
            cin >> f;
            int i=linear(l,len,f);
            cout << "Found at index: "<<i << endl;
        }
        else if (c==2){
            int l[10];
            for (int i=0;i<10;i++){
                l[i]=list[i];
            }
            insertsort(l,len);
            int f;
            printlist(l,len);
            cout << "Enter number to find: ";
            cin >> f;
            int i=binary(l,0,len,f);
            cout << "Found at index: "<<i << endl;
        }
        else if (c==3) break;
    }
    cout <<"Program Exited\n";
}
