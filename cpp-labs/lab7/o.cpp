#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k; 
    string v = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans;
    while(n){
        if(n % k > 9){
            ans += v[n % k - 10];
        }
        else{
            ans += char((n % k) + '0');
        }
        n /= k;
    }
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i]; 
    }
    return 0; 
    
}






#include <iostream>
#include <string>
using namespace std;

string wow(int n, int k) {
    string v = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string a;

    if (n == 0) {
        return "0";
    }

    if (n % k > 9) {
        a += v[n % k - 10];
    } else {
        a += char((n % k) + '0');
    }

    return wow(n / k, k) + a;
}

int main() {
    int n, k;
    cin >> n >> k;

    string a = wow(n, k);

    cout << a;

    return 0;
}
