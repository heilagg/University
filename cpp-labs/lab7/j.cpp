#include <iostream>
#include <cctype>
using namespace std;

int wow(int n){
    if(n == 0){
        return 0;
    }
    else{
        int q = n % 10;
        return q/2 + wow(n/10);
    }
}

int main() {
    int n;
    cin>>n;
    cout<<wow(n);

    return 0;
}