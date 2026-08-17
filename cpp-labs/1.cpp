#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(a + b);
    }
    for(int i = 0; i < v.size(); i++){
        int cnt = 0;
        for(int j = 0; j < i; j++){
            if(v[i] == v[j]){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}