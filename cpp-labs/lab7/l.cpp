#include <iostream>
#include <cmath>
using namespace std;
int main(){
    string n;
    cin >> n;
    int cnt = n.size() - 1, chk = 1;
    for(int i = 0; i < n.size(); i++){
        if(n[i] != n[cnt]){
            chk = 0;
            cout << "No";
            return 0;
        }
        cnt--;
    }
    cout << "Yes";
    return 0;
}





#include <iostream>
#include <string>
using namespace std;

bool wow(string str, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (str[start] != str[end]) {
        return false;
    }

    return wow(str, start + 1, end - 1);
}

int main() {
    string n;
    cin >> n;

    bool chk = wow(n, 0, n.size() - 1);
    if (chk) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
