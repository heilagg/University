#include <bits/stdc++.h> 
using namespace std;


int main(){
    int n;
    cin >> n;
    map<string, int> m1[n+20];
    string s[n + 20];
    int e[n + 20];
    int v = n;
    int sum = 0;
    while(n--){
        pair<string, int> cont1;
        pair<string, int> cont2;
        cin >> cont1.first >> cont1.second; 
        cin >> cont2.first >> cont2.second;
        int chk = 1;
        for(int i = 0; i <= v; i++){
            if(m1[i][cont1.first] == cont1.second and m1[i][cont2.first] == cont2.second){
                chk = 0;
            }
        }
        if(chk == 1){
            m1[n][cont1.first] = cont1.second;
            m1[n][cont2.first] = cont2.second;
            sum++;
            s[sum] = cont1.first + " and " + cont2.first;
            e[sum] = cont1.second + cont2.second;
        }
    }
    for(int i = 1; i<= sum; i++){
        for(int j = i; j<= sum; j++){
            if(s[i] > s[j] and s[i] != s[j]){
                swap(s[i], s[j]);
                swap(e[i], e[j]);
            }
        }
    }
    for(int i = 1; i<= sum; i++){
        cout << s[i] << " " << e[i] << endl;
    }

    return 0;
}

