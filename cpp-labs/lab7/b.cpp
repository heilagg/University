#include <iostream>
#include <cmath>
using namespace std;


void wow(int n){
    if(n > 1){
        wow(n/2);
        cout<<n%2;
    }
    else{
        cout<<n;
    }


}


int main() {
    int n;
    cin>>n;
    wow(n);


    return 0;
}
