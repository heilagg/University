#include <bits/stdc++.h>
using namespace std;
 
int main(){ 
    int n, k; 
    cin >> n; 
    vector <int> v(n);

    for (int i = 0; i < n; i++){
      cin >> v[i]; 
    }

    cin >> k; 

    int min_diff = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < n; ++i) {
        int diff = abs(v[i] - k);
        if (diff < min_diff) {
            min_diff = diff;
            min_index = i;
        }
    }
    cout << min_index; 
}