#include <iostream>
#include <cmath>
using namespace std;


int wow(int n){
    if(n == 0){
        return 0;
    }
    else{
        return n%10 + wow(n/10);
    }
}


int main() {
    int n;
    cin>>n;
    cout<<wow(n);


    return 0;
}





#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    string n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n.size(); i++){
        sum += (n[i] - '0');
    }
    cout << sum;
    return 0;
}




#include <iostream>
using namespace std;

int wow(string n, int index) {
    if (index == n.size()) {
        return 0;
    }

    return (n[index] - '0') + wow(n, index + 1);
}

int main() {
    string n;
    cin >> n;

    int sum = wow(n, 0);
    cout << sum;

    return 0;
}
