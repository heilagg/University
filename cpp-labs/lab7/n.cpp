#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k; 
    int a[10020];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
    for(int i = 1; i < n; i++){
        if((a[i] - a[i - 1]) <= k){
            cout << "cheater";
            return 0;
        }
    }
    cout << "no";
    return 0; 
}