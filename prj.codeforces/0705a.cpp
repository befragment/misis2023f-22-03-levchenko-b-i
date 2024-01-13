#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::cout << "I hate";
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            std::cout << " that I hate";
        } else {
            std::cout << " that I love";
        }
    }
    std::cout << " it" << std::endl;
}
