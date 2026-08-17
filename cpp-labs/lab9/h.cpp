#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    map<string, int> m;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (m.find(v[i]) == m.end()) {
            m[v[i]] = i + 1;
        }
    }

    sort(v.begin(), v.end());

    for (const auto& str : v) {
        if (m[str] != 0) {
            cout << str << " " << m[str] << endl;
            m[str] = 0;
        }
    }

    return 0;
}
