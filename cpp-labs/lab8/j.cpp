#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    int n, max, min;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    max = v[0];
    min = v[0];

    
    for(int i = 0; i < v.size(); i++){
        if(v[i] > max){
            max = v[i];
        }
        if(v[i] < min){
            min = v[i];
        }
    } 

    cout<<max - min;
    return 0;
}