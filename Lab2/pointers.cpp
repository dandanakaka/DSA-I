#include <iostream>
#include <math.h>
using namespace std;
bool check(int *a,int *b){
    if (*a==*b) return true;
    else return false;
}
bool Pallindrone(int *num){
    int *original=(int *)malloc(sizeof(int));
    *original=*num;
    int *sum=(int *)malloc(sizeof(int));
    *sum=0;
    while (*num>0){
        int d=(*num)%10;
        *sum = (*sum)*10+d;
        *num=(*num)/10;
    }
    bool *a=(bool *)malloc(sizeof(bool));
    *a=check(original,sum);
    free(sum);
    return *a;
}
bool Armstrong(int *num){
    int *original=(int *)malloc(sizeof(int));
    *original=*num;
    int *sum=(int *)malloc(sizeof(int));
    *sum=0;
    int digits=floor(log10(*num)+1);
    while (*num>0){
        int d=(*num)%10;
        *sum+=pow(d,digits);
        *num=(*num)/10;
    }
    bool *a=(bool *)malloc(sizeof(bool));
    *a=check(original,sum);
    free(sum);
    return *a;
}
bool Perfect(int *num){
    int *original=(int *)malloc(sizeof(int));
    *original=*num;
    int *sum=(int *)malloc(sizeof(int));
    *sum=0;
    int* i = (int *)malloc(sizeof(int));
    for (*i = 1; *i < (*num); (*i)++) {
        if ((*num) % (*i) == 0) {
            *sum = (*sum) + (*i);
        }
    }
    bool *a=(bool *)malloc(sizeof(bool));
    *a=check(original,sum);
    free(original);
    free(sum);
    free(i);
    return *a;
}
int main(){
    int *num=nullptr;
    int *original=nullptr;
    char c;
    while (true){
        cout<<"a.Pallindrone\nb.Armstrong\nc.Perfect\nd.Exit\nEnter Choice: ";
        cin >> c;


        if (c=='a'){
            num=(int *)malloc(sizeof(num));
            original=(int *)malloc(sizeof(int));
         
            cout<<"Enter Number: ";
            cin >> *num;
            *original=*num;
            if (Pallindrone(num)) cout<<*original <<" is pallindrone\n";
            else cout<<*num<<" is not pallindrone\n";
        }
        else if (c=='b'){
            num=(int *)malloc(sizeof(num));
            original=(int *)malloc(sizeof(int));
            cout<<"Enter Number: ";
            cin >> *num;
            *original=*num;
            if (Armstrong(num)) cout<<*original <<" is Armstrong\n";
            else cout<<*num<<" is not Armstrong\n";

        }
        else if(c=='c'){
            num=(int *)malloc(sizeof(num));
            original=(int *)malloc(sizeof(int));
            cout<<"Enter Number: ";
            cin >> *num;
            *original=*num;
            if (Perfect(num)) cout<<*num <<" is Perfect\n";
            else cout<<*num<<" is not Perfect\n";
        }

        else if(c=='d'){
            free(original);
            free(num);
            break;
        }
        else cout<<"Invalid Input\n";
    }
}
