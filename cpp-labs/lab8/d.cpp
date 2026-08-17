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
    //sort(v.begin(), v.end());
    v.erase(v.begin() + m);
    for(int i = 0; i < n - 1; i++){
        cout<<v[i]<<" ";
    }

    return 0;
}