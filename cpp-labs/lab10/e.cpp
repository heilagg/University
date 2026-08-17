/*#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n,m,k,numst;
    string city;
    numst = 0;
    cin >> n;
    vector<pair<string,int>> name;

    for(int i = 0; i < n; i++){
        cin >> n;
        for(int m = 0; i < m; i++){
            cin>>city>>numst;
            cin >> name[i].first() >> name[i].second();
        }
        for(int i = 0; i < k; i++){
            cin >> name[i] >> num[i];
        }
    }
    

    sort(name.begin(), name.end());


    for(int i = 0; i < n; i++){
        cout<< name[i] << " " << num[i] << endl;
    }

    return 0;
}*/



#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    cin >> n;
    set<pair<string, double>> s1;
    while(n--){
        int v;
        cin >> v;
        while(v--){
            pair<string, double> s2;
            cin >> s2.first >> s2.second;
            auto it = s1.begin();
            for(it = s1.begin(); it != s1.end(); it++){
                if(it->first == s2.first){
                    break;
                }
            }
            if(it == s1.end()){
                s1.insert(s2);
            }
            else{
                pair<string, double> g = *it;
                s1.erase(it);
                g.second += s2.second;
                s1.insert(g);
            }
        }
    }
    float sum = 0;
    for(auto i: s1){
        sum += i.second;
    }
    vector<pair<string, double>> t;
    for(auto i: s1){
        cout << i.first << " " << (i.second / sum) * 100 << endl; 
    }
    return 0;
}
