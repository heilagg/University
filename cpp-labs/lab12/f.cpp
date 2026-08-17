#include <bits/stdc++.h>
using namespace std;

void isTasty(string s){
    int sum = 0;

    for(int i = 0; i < s.size(); i++){
        sum += s[i];
    }
    if(sum >= 300){
        cout<<"It is tasty!";
    }
    else{
        cout<<"Oh, no!";
    }
}

int main() {
    string s;
    cin >> s;
    isTasty(s);

    return 0;
}