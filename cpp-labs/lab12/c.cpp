#include <bits/stdc++.h>
using namespace std;


int main(){ 
    int n, a = 0; 
    cin >> n; 
    int arr[n]; 

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < n; i++){
        a^=arr[i];
    }

    if((a&(a-1)) == 0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }



    return 0;
}