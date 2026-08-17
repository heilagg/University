#include <bits/stdc++.h> 
using namespace std;

long long wow(const vector<int>& heights) {
    int n = heights.size();
    stack<int> indexes;
    long long maxArea = 0;

    for (int i = 0; i <= n; ++i) {
        while (!indexes.empty() && (i == n || heights[i] < heights[indexes.top()])) {
            int h = heights[indexes.top()];
            indexes.pop();
            int width = indexes.empty() ? i : i - indexes.top() - 1;
            maxArea = std::max(maxArea, static_cast<long long>(h) * width);
        }
        indexes.push(i);
    }

    return maxArea;
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    long long cf = wow(heights);
    cout << cf << std::endl;

    return 0;
}
