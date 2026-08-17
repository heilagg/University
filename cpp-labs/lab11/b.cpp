#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,s = 0;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; i++){
        cin >> v[i];
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < n; i++){
		if (v[i]==v[i+1]){
            s++;
        }
	}

	if (s > 0){
        cout << "NO";
    }
	else{
		cout << "YES";
	}
    return 0;
}