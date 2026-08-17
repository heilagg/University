#include <bits/stdc++.h>
using namespace std;

void printTotalNumberAndTheMaximumNumberOfChips(int arr[], int n) {
    int totalChips = 0;
    int maxChips = 0;

    for (int i = 0; i < n; ++i) {
        totalChips += arr[i];
        if (arr[i] > maxChips) {
            maxChips = arr[i];
        }
    }

    cout << totalChips << " " << maxChips << endl;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    printTotalNumberAndTheMaximumNumberOfChips(arr, n);

    return 0;
}
