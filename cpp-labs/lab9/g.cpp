#include <bits/stdc++.h> 
using namespace std;

string wow(const string& a) {
    vector<char> r;

    for (char digit : a) {
        if (digit == '0' || r.empty() || r.back() == '0') {
            r.push_back(digit);
        } else {
            r.pop_back(); // Remove the last '1'
        }
    }

    return string(r.begin(), r.end());
}

int main() {
    string a;
    cin >> a;

    cout << wow(a);

    return 0;
}
