//Program to implement Nene's Game
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve();

int main(){
    int t;
    cout<<"Enter Number of Test Cases:";
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


void solve(){
    int q;
    cout<<"Enter Number of inputs of N (Q):";
    cin>>q;
    int k;
    cout<<"Number of Elements in array a:";
    cin>>k;
    vector<int> a(k);
    for (int i=0;i<k;i++){
        cout<<"Enter Element "<<i+1<<":";
        cin>>a[i];
    }
    while (q--){
        int n;
        cout<<"Enter Number of Players N:";
        cin>>n;
        cout << min(n, a[0] - 1) << "\n";
    }
}
