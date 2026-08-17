#include <bits/stdc++.h> 
using namespace std;

int main() {
    string n;
    cin >> n;

    stack<char> stack;

    for (char c : n) {
        if (stack.empty()) {
            stack.push(c);
        } else {
            int num = stack.top() - '0';
            int current = c - '0';
            int combined = num * 10 + current;

            if (combined == 4 || combined == 9 || combined == 16 || combined == 25 || combined == 36 || combined == 49 || combined == 64 || combined == 81) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
    }

    if (stack.empty()) {
        cout << "Stack is empty";
    } else {
        string reversedNumber = "";
        while (!stack.empty()) {
            reversedNumber += stack.top();
            stack.pop();
        }
        cout << reversedNumber;
    }

    return 0;
}