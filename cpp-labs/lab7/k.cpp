#include <iostream>
#include <string>
using namespace std;

int wow(string n, int index, int maxd) {
    if (index == n.size()) {
        return maxd;
    }

    int currentDigit = n[index] - '0';
    maxd = max(maxd, currentDigit);

    return wow(n, index + 1, maxd);
}

int main() {
    string n;
    cin >> n;

    int max1 = wow(n, 0, -9999);
    cout << max1;

    return 0;
}




#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    string n;
    cin >> n;
    int max1 = -9999;
    for(int i = 0; i < n.size(); i++){
        max1 = max(max1, int(n[i]) - '0');
    }
    cout << max1;
    return 0;
}