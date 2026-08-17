#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[10020];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    int l = 0, r = n;
    int i = (l + r) / 2;
    bool chk = 1;
    while(l != r){
        if(a[i] < k and a[i + 1] > k){
            cout << "No";
            return 0;
        }
        if(k > a[n - 1]){
            cout << "No";
            return 0;
        }
        if(a[i] == k){
            cout << "Yes";
            chk = 0;
            break;
            return 0;
        }
        else{
            if(a[i] > k){
                r = i;
            }
            else{
                l = i;
            }
        }
        i = (l + r) / 2;
    }
    if(chk){
        cout << "No";
    }
    return 0;
}







#include <iostream>
#include <algorithm>
using namespace std;

bool wow(int a[], int l, int r, int k) {
    if (l > r) {
        return false;
    }

    int mid = l + (r - l) / 2;

    if (a[mid] == k) {
        return true;
    } else if (a[mid] < k) {
        return wow(a, mid + 1, r, k);
    } else {
        return wow(a, l, mid - 1, k);
    }
}

int main() {
    int n;
    cin >> n;
    
    int a[10020];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n); 

    int k;
    cin >> k;

    if (wow(a, 0, n - 1, k)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
