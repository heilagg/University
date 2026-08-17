#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    int n, m, k;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
     
    cin>>m>>k;
     

    v.erase(v.begin() + m, v.begin() + k + 1);
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
