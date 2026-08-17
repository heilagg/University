#include <bits/stdc++.h> 
using namespace std;

#include <iostream>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::unordered_map<std::string, std::string> credentials;

    for (int i = 0; i < n; ++i) {
        std::string login, password;
        std::cin >> login >> password;
        credentials[login] = password;
    }


    for (int i = 0; i < m; ++i) {
        std::string login, password;
        std::cin >> login >> password;


        if (credentials.find(login) == credentials.end()) {
            std::cout << "login error" << std::endl;
        } else {

            if (credentials[login] != password) {
                std::cout << "password error" << std::endl;
            } else {
                std::cout << "correct password" << std::endl;
            }
        }
    }

    return 0;
}

