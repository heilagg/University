#include <bits/stdc++.h> 
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    sort(points.begin(), points.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first; 
        }
        return a.second < b.second; 
    });

    for (const auto& point : points) {
        cout << point.first << " " << point.second <<endl;
    }

    return 0;
}
