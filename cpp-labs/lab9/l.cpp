#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first += arr[i].second; 
        arr[i].second = i; 
    }

    sort(arr.begin(), arr.end());

    for (const auto& elem : arr) {
        std::cout << elem.second + 1 << " "; 
    }

    return 0;
}
