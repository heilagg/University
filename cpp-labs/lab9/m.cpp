#include <bits/stdc++.h> 
using namespace std;


int main() {
    int n;
    cin >> n;
    queue<string> boysQueue;

    for (int i = 0; i < n; ++i) {
        int actionType;
        std::cin >> actionType;

        if (actionType == 1) {
            string name;
            cin >> name;
            boysQueue.push(name); 
        } else if (actionType == 2) {
            if (!boysQueue.empty()) {
                boysQueue.pop(); 
            } else {
                cout << "queue is empty" << endl; 
            }
        }

        if (!boysQueue.empty()) {
            cout << boysQueue.front() << endl; 
        } else {
            cout << "queue is empty" << endl; 
            }
    }

    return 0;
}
