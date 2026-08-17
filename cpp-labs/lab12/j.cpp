#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> firstArray(n);
    unordered_set<int> uniqueSums;

    for (int i = 0; i < n; ++i) {
        cin >> firstArray[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            uniqueSums.insert(firstArray[i] + firstArray[j]);
        }
    }

    cin >> m;
    vector<int> secondArray(m);

    for (int i = 0; i < m; ++i) {
        cin >> secondArray[i];
    }

    for (int i = 0; i < m; ++i) {
        if (uniqueSums.find(secondArray[i]) != uniqueSums.end()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

