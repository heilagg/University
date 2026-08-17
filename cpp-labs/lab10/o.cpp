#include <bits/stdc++.h> 
using namespace std;


void wow(int i){
    string ans;
    while(i){
        ans += to_string(i % 2);
        i /= 2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
int main(){
    int n;
    cin >> n;
    vector<int> v;
    while(n--){
        int d;
        cin >> d;
        v.push_back(d);
    }
    for_each(v.begin(), v.end(), wow);
    return 0;
}

