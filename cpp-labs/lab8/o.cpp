#include <bits/stdc++.h> 
using namespace std;

int main() {
    string s;
    cin >> s;

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    vector<char> unique_letters;

    for (char c : s) {
        if (find(unique_letters.begin(), unique_letters.end(), c) == unique_letters.end()) {
            if (isalpha(c)) {
                unique_letters.push_back(c);
            }
        }
    }


    sort(unique_letters.begin(), unique_letters.end());

    int num_unique_letters = unique_letters.size();

    cout << num_unique_letters << std::endl;

    for (char letter : unique_letters) {
        cout << letter << " ";
    }

    return 0;
}
