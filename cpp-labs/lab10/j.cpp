#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    rotate(v.begin(), v.begin() + m, v.end());

    reverse(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
