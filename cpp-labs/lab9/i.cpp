#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v;
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        bool found = false;
        for (const string& user : v) {
            if (user == s) {
                cout << "user already exists" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            v.push_back(s);
            cout << "new user added" << endl;
        }
    }

    return 0;
}
