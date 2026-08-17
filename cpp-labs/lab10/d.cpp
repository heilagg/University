#include <bits/stdc++.h> 
using namespace std;

bool wow(const vector<int>& a, const vector<int>& b) {
    int sum_a = 0, sum_b = 0;
    for (int num : a) {
        sum_a += num;
    }
    for (int num : b) {
        sum_b += num;
    }

    if (sum_a != sum_b) {
        return sum_a < sum_b; 
    }

    if (a.size() != b.size()) {
        return a.size() < b.size(); 
    }

    for (auto i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }

    return false; 
}



int main() {
    int N;
    cin >> N;

    vector<vector<int>> arr(N);
    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        arr[i].resize(M);
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    sort(arr.begin(), arr.end(), wow);

    for (const vector<int>& row : arr) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
