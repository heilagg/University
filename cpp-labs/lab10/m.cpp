#include <bits/stdc++.h> 
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v1;
    vector<int> v2;
    while(n--){
        int k; 
        cin >> k;
        v1.push_back(k);
    }
    auto it = unique(v1.begin(), v1.end());
    v1.resize(it - v1.begin());
    while(m--){
        int k;
        cin >> k;
        v2.push_back(k);
    }
    auto it1 = unique(v2.begin(), v2.end());
    v2.resize(it1 - v2.begin());
    vector<int> merged;
    int i = 0;
    while(!v2.empty() or !v1.empty()){
        if(!v1.empty()){
            merged.push_back(v1[0]);
            v1.erase(v1.begin());
        }
        if(!v2.empty()){
            merged.push_back(v2[0]);
            v2.erase(v2.begin());
        }
        i++;
    }
    auto it2 = unique(merged.begin(), merged.end());
    merged.resize(it2 - merged.begin());
    for(auto i: merged){
        cout << i << " ";
    }
    return 0;
}

