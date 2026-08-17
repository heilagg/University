#include <iostream>
#include <cmath>
using namespace std;


int wow(string n){
    int m = stoi(n);
    int q = m % 10;

    if(m == 0){
        return 0;
    }
    else{
        if(q%2==0){
            return 1 + wow(m/10);
        }
        else{
            return wow(m/10);
        }
        
    }
}


int main() {
    string n;
    cin>>n;

    cout<<wow(n);
    return 0;
}







#include <iostream>
#include <string>
using namespace std;

int wow(string n, int index) {
    if (index == n.size()) {
        return 0;
    }

    int d = n[index] - '0';
    int e = (d % 2 == 0) ? 1 : 0;

    return e + wow(n, index + 1);
}

int main() {
    string n;
    cin >> n;

    int cnt = wow(n, 0);
    cout << cnt;

    return 0;
}
