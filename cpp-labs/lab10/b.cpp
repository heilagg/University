#include <bits/stdc++.h> 
using namespace std;



std::vector<long long> calculateSequence(int N) {
    std::vector<long long> sequence;
    sequence.push_back(1); 
    for (int n = 1; n <= N; ++n) {
        long long value = pow(n, n);
        sequence.push_back(value);
    }
    return sequence;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<long long> resultSequence = calculateSequence(N);

    // Outputting the sequence
    for (long long num : resultSequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


