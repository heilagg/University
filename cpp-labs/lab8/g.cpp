#include <bits/stdc++.h> 
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int k;
    cin >> k;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (numbers[i] > k && isPrime(numbers[i])) {
            count++;
        }
    }

    cout << count;

    return 0;
}
