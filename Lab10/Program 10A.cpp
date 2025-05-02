#include<iostream>
#include<vector>
using namespace std;

void solve();

int main(){
    solve();
    return 0;
}

void solve(){
    cout << endl;
    int test_case;
    cout << "Enter number of test case: ";
    cin >> test_case;
    cout << endl;
    while(test_case--){
        int num;
        cout << "Enter number of integers: ";
        cin >> num;
        cout << endl;
        vector <int> array(num);
        for(int i=0;i<num;i++){
            cin >> array[i];
        }
        int count=0;
        for(int i=0;i<num-1;i++){
           int j=i+1; 
           while(j<num){
            if(array[i]==array[j]){
                    count=i+1;
                    break;
            }
            else{
                    j++;
            }
            }
        }
        cout << endl;
        cout << count << endl ;
        cout << "----------------------"<<endl;
    }
    cout << "Exiting...." << endl;
}
