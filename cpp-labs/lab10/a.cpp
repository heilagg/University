#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> name(n);
    vector<int> num(n);
    for(int i = 0; i < n; i++){
        cin >> name[i] >> num[i];
    }

    sort(name.begin(), name.end());
    sort(num.begin(), num.end());

    for(int i = 0; i < n; i++){
        cout<< name[i] << " " << num[i] << endl;
    }

    return 0;
}
