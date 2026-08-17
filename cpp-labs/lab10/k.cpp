#include <bits/stdc++.h> 
using namespace std;

bool wow(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int sum = count_if(v.begin(), v.end(), [](int n) {
        return wow(abs(n));
    });

    cout << sum << endl;

    return 0;
}

