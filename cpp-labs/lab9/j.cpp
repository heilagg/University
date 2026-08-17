#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;

    map<std::string, int> m;

    for (int i = 0; i < n; ++i) {
        string d;
        int e;
        cin >> d >> e;

        m[d] += e;
    }

    for (const auto& entry : m) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}
