#include <bits/stdc++.h> 
using namespace std;


int wow(vector<int> v){
    int j = v.size() - 1;
    for(int i = 0; i < v.size(); i++){ 
        if(v[i] != v[j]){
            return 0;
        }
        j--;
    }
    return 1;
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
    sort(v.begin(), v.end());
    int ch = 0;
    while(next_permutation(v.begin(), v.end())){
        if(wow(v)){
            for(auto i: v){
                cout << i << " ";
            }
            ch = 1;
            break;
        }
    }
    if(!ch){
        cout << "Impossible";
    }
    return 0;
}
