#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    if(str == "MON"){
        cout << 6;
    }
    if(str == "TUE"){
        cout << 5;
    }
    if(str == "WED"){
        cout << 4;
    }
    if(str == "THU"){
        cout << 3;
    }
    if(str == "FRI"){
        cout << 2;
    }
    if(str == "SAT"){
        cout << 1;
    }
    if(str == "SUN"){
        cout << 7;
    }

    return 0;
}