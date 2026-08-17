#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int k;
    cin >> k;

    sort(numbers.begin(), numbers.end(), greater<int>());

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += numbers[i];
    }

    cout << sum << std::endl;

    return 0;
}
