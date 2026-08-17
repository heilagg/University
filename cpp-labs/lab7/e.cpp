#include <iostream>
#include <cmath>
using namespace std;


bool wow(int n){

    if(n == 1){
        return true;
    }
    else if(n % 2 == 1 || n==0){
        return false;
    }
    else{
        return wow(n/2);
    }
}


int main() {
    int n;
    cin>>n;
    if(wow(n)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }


    return 0;
}