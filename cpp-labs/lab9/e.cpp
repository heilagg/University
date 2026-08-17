#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> v;

    for (int i = 0; i < n; ++i) {
        string number;
        cin >> number;
        v[number]++;
    }

    int countOfThrees = 0;

    for (const auto &entry : v) {
        if (entry.second == 3) {
            countOfThrees++;
        }
    }

    cout << countOfThrees << endl;

    return 0;
}
