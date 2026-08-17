#include <bits/stdc++.h> 
using namespace std;
 

bool wow(const string& str) {
    vector<char> st;

    for (char c : str) {
        if (c == '(') {
            st.push_back(c);
        } else if (c == ')') {
            if (st.empty() || st.back() != '(') {
                return false;
            }
            st.pop_back();
        }
    }

    return st.empty();
}

int main() {
    std::string bracketSequence;
    std::cin >> bracketSequence;

    if (wow(bracketSequence)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
