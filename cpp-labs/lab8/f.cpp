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

    v.insert(v.begin() + m,k);
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    } 


    return 0;
}