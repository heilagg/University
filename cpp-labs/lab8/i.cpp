#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    int n, m;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
     
    cin>>m;
    bool b = false;

    
    for(int i = 0; i < v.size(); i++){
        if(m == v[i]){
            b = true;
            break;
        }
    } 

    if(b){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}