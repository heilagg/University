#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int wow(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    else{
        return wow(n-1) + wow(n-2);
    }
}
int main(){
    int n;
    cin >> n;
    cout << wow(n);
    return 0;
}