#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::string abc = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < n; i++) {
        char c = tolower(s[i]);
        abc.erase(std::remove(abc.begin(), abc.end(), c), abc.end());
    }
    abc.size() == 0 ? std::cout << "YES\n" : std::cout << "NO\n";
    return 0;
}
