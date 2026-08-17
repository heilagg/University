#include <bits/stdc++.h> 
using namespace std;

void wow(vector<int>& v, int n) {
    v2 = sort(v.begin(), v.end());

    do {
        for (int i = 0; i < n; ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.begin() + n));
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> v2(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if(v[1] != v[0]){
        wow(v, n);
    }  
    else if(v == sort(v.begin(), v.end())){

    } 
    else{
        cout<<v[0];
    }


    return 0;
}
