#include <bits/stdc++.h> 
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int s = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (v[i] == v[i + 1]) {
            s++;
            while (i < n - 1 && v[i] == v[i + 1]) {
                i++;
            }
        }
    }

    cout << s;

    return 0;
}
