#include <bits/stdc++.h>
using namespace std;


bool wow(int (*arr)[100], int n, int m, int k){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] > k){
                return false;
            }
        }
    }
    return true;

}
 
int main(){ 
    int n, m, k; 
    cin >> n >> m; 
    int arr[n][100]; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }

    cin>>k;

    if(wow(arr, n, m, k)){
        cout<<"No penalty for today.";
    }
    else{
        cout<<"Penalty!";
    }



    return 0;
}