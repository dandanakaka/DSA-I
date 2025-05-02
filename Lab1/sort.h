#include <iostream>
using namespace std;
void printlist(int l[],int len){
    for (int i = 0; i < len; i++){
        cout <<l[i]<<" ";
    }
    cout << endl;
}
void insertsort(int arr[],int len){
    int key,j;
    for (int i=0;i<len;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
