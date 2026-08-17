#include <iostream>
#include <cctype>
using namespace std;

void wow(int n){
    if(n == 1){
        cout << 1<<" ";
    }
    else{
        wow(n - 1);
        cout<<n<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    wow(n);

    return 0;
}