//Program to implement list ADT in C++
#include <iostream>
using namespace std;
void reverse(int*,int,int);

class list{
private:
    int array[5];
    int cur;
public:
    list(){
        cur=-1;
    }
    bool insertbeg(int);
    bool insertend(int);
    bool insertpos(int,int);
    int deletebeg();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();
    bool rotate(int);
};


int main(){
    int c;
    class list array;
    while(true){
        cout<<"1:Insert Beginning\n2:Insert End\n3:Insert Position\n4:Delete Beginning\n5:Delete End\n6:Delete Position\n7:Search\n8:Display\n9:Rotate\n0:Exit\n";
        cout<<"Enter Choice: ";
        cin>>c;
        if (c==1){
            // Insert Value to Beginning
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            array.insertbeg(value);
        }
        else if (c==2){
            // Insert Value to End
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            array.insertend(value);
        }
        else if (c==3){
            // Insert Value to Index
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            int index;
            cout<<"Enter Index: ";
            cin>>index;
            array.insertpos(value,index);
        }
        else if (c==4){
            // delete first element
            array.deletebeg();
        }
        else if (c==5){
            // delete last element
            array.deleteend();
        }
        else if (c==6){
            // delete element at given index
            int index;
            cout<<"Enter Index: ";
            cin>>index;
            array.deletepos(index);
        }
        else if (c==7){
            // search for element
            int value;
            cout<<"Enter Value: ";
            cin>>value;
            array.search(value);
        }
        else if (c==8){
            // display array
            array.display();
        }
        else if (c==9){
            //Rotate Array
            int r;
            cout<<"Enter Number: ";
            cin>>r;
            array.rotate(r);
        }
        else if(c==0){
            //Exit Menue;
            break;
        }  
    }
    cout<<"Program Exited"<<endl;
    return 0;
}


bool list::insertbeg(int num){
    if (cur==4){
        cout<<"Array Full\n";
        return 0;
    }
    for (int i=cur;i>=0;i--){
        array[i+1]=array[i];
    }
    array[0]=num;
    cur++;
    return 1;
}

void list::display(){
    for (int i=0;i<=cur;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

bool list::insertend(int num){
    if (cur==4){
        cout<<"Array Full\n";
        return 0;
    }
    array[++cur]=num;
    return 1;
}

bool list::insertpos(int num,int index){
    if (cur==4){
        cout<<"Array Full\n";
        return 0;
    }
    for (int i=cur;i>=index;i--){
        array[i+1]=array[i];
    }
    array[index]=num;
    cur++;
    return 1;
}

int list::deletebeg(){
    if (cur==-1){
        cout<<"Array Empty\n";
        return -1;
    }
    int temp=array[0];
    for (int i=0;i<cur;i++){
        array[i]=array[i+1];
    }
    cur--;
    return temp;
}
int list::deleteend(){
    if (cur==-1){
        cout<<"Array Empty\n";
        return -1;
    }
    int temp=array[cur];
    cur--;
    return temp;
}

int list::search(int num){
    if (cur==-1){
        cout<<"Array Empty\n";
        return -1;
    }
    for (int i=0;i<=cur;i++){
        if (array[i]==num){
            cout<<"Element found at Index "<<i<<endl;
            return i;
        }
    }
    cout<<"Element Not Found\n";
    return -1;
}

int list::deletepos(int index){
    if (cur==-1){
        cout<<"Array Empty\n";
        return -1;
    }
    int temp=array[index];
    for (int i=index;i<cur;i++){
        array[i]=array[i+1];
    }
    cur--;
    return temp;
}

bool list::rotate(int k){
    if (cur!=4){
        cout<<"Can only rotate full list\n";
        return 0;
    }
    if (k>=5) k=k%5;
    reverse(array,0,4);
    reverse(array,0,k-1);
    reverse(array,k,4);
    return 1;
}



//Helper Functions
void reverse(int array[],int l,int r){
    while(l<r){
        int temp=array[l];
        array[l]=array[r];
        array[r]=temp;
        l++;
        r--;
    }
}
