#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    int n, m, k, sum = 0;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
     
    sort(v.begin(), v.end());


    for(int i = 0; i < v.size(); i++){
        if(v[i] != v [i+1] && v[i] % 2 == 1){
            cout<<v[i]<<" ";
        }
    } 


    return 0;
}