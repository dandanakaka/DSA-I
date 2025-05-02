#include<iostream>
#include<vector>
#include<string>
#include<map>
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
        int num_word;
        cout << "Enter number of words: ";
        cin >> num_word;
        vector <string> P1,P2,P3;
        map<string, int> word_count;
        //input
        cout << "Player 1:" << endl;
        for (int i = 0; i < num_word; i++) {
            string word;
            cout << "Enter a 3-letter word: ";
            cin >> word;
            if (word.length() == 3) {
                P1.push_back(word);
                word_count[word]++;
            } else {
                cout << "Invalid input! Please enter exactly 3 letters." << endl;
                i--;
            }
        }

        cout << "Player 2:" << endl;
        for (int i = 0; i < num_word; i++) {
            string word;
            cout << "Enter a 3-letter word: ";
            cin >> word;
            if (word.length() == 3) {
                P2.push_back(word);
                word_count[word]++;
            } else {
                cout << "Invalid input! Please enter exactly 3 letters." << endl;
                i--;
            }
        }

        cout << "Player 3:" << endl;
        for (int i = 0; i < num_word; i++) {
            string word;
            cout << "Enter a 3-letter word: ";
            cin >> word;
            if (word.length() == 3) {
                P3.push_back(word);
                word_count[word]++;
            } else {
                cout << "Invalid input! Please enter exactly 3 letters." << endl;
                i--;
            }
        }

        // Score calculation
        int p1 = 0, p2 = 0, p3 = 0;
        for (const string& word : P1) {
            p1 += (word_count[word] == 1) ? 3 : (word_count[word] == 2) ? 1 : 0;
        }
        for (const string& word : P2) {
            p2 += (word_count[word] == 1) ? 3 : (word_count[word] == 2) ? 1 : 0;
        }
        for (const string& word : P3) {
            p3 += (word_count[word] == 1) ? 3 : (word_count[word] == 2) ? 1 : 0;
        }

        cout << "\nPlayer 1 scored: " << p1 << " points" << endl;
        cout << "Player 2 scored: " << p2 << " points" << endl;
        cout << "Player 3 scored: " << p3 << " points" << endl;
        cout << "------------------------" << endl;
    }
}
