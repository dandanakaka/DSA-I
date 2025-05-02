#include <iostream>
using namespace std;

void printlist(int l[],int len){
    for (int i = 0; i < len; i++){
        cout <<l[i]<<" ";
    }
    cout << endl;
}

void bubblesort(int arr[],int len){
    for (int i=0;i<len;i++){
        for(int j=0;j<len-1-i;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"Sorted Array:\n";
    printlist(arr,len);
}

void selectionsort(int arr[],int len){
    for (int i=0;i<len;i++){
        int j=i;
        for(j;j<len;j++){
            if (arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"Sorted Array:\n";
    printlist(arr,len);
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
    cout<<"Sorted Array:\n";
    printlist(arr,len);
}

int main(){
    int list[10]={4,1,9,6,2,3,5,62,1,0};
    int len=10;
    while (true){
        int c=4;
        cout <<"Enter Choice\nbubble:1 \nselection:2 \nInsertion:3 \n4:exit\n";
        cout << "Enter choice: ";
        cin >> c;
        if (c==1){
            int l[10];
            for (int i=0;i<10;i++)
                l[i]=list[i];
            cout<<"Original Array:\n";
            printlist(list,len);
            bubblesort(l,len);
        }
        else if (c==2){
            int l[10];
            for (int i=0;i<10;i++)
                l[i]=list[i];
            cout<<"Original Array:\n";
            printlist(list,len);
            selectionsort(l,len);
        }

        else if (c==3){
            int l[10];
            for (int i=0;i<10;i++)
                l[i]=list[i];
            cout<<"Original Array:\n";
            printlist(list,len);
            insertsort(l,len);
        }

        else if (c==4) break;
    }
    cout << "Program Exited";
}
