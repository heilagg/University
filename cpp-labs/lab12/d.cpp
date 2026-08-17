#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<int> array(n);

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int max_gcd = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int current_gcd = gcd(array[i], array[j]);
            if (current_gcd > max_gcd) {
                max_gcd = current_gcd;
            }
        }
    }

    cout << max_gcd << endl;

    return 0;
}
