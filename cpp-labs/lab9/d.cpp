#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    int n, m, k,l;
    cin>>n;
    m = 0;
    l = 0;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }


    for(int i = 0; i < n; i++){
        if(v[i] == v[i - 1]){
            m++;
            if(m == 3){
                l++;
                m = 0;
            }
        }
        
    } 
    cout<<m;
    return 0;
}