#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    int m, k;
    cin>>m>>k;
     
    for(int i = m, j =k; i < j; i++, j--){
        swap(v[i], v[j]);
    }

    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
 
    return 0;
}