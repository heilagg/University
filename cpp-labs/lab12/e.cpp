#include <bits/stdc++.h>
using namespace std;

void wow(int n) {
    string h = "";
    string hd = "0123456789ABCDEF";

    while (n > 0) {
        int r = n % 16;
        h = hd[r] + h;
        n /= 16;
    }

    cout << h << endl;
}

int main() {
    int N;
    cin >> N;

    wow(N);

    return 0;
}
