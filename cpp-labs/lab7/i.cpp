#include <iostream>
#include <cctype>
using namespace std;

int wow(){
    int n;
    cin>>n;
    
    if(n == 0){
        return 0;
    }
    else{
        return n + wow();
    }
}

int main() {
    cout<<wow();

    return 0;
}