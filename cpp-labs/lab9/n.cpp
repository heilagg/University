#include <bits/stdc++.h> 
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int s = 0;
    unordered_set<int> numsSet(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x = arr[i] ^ arr[j];
            if (numsSet.find(x) != numsSet.end()) {
                s++;
            }
        }
    }

    cout << s << endl;

    return 0;
}


