#include <iostream>
#include <vector>
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
    for (auto it = vec.begin(); it < vec.end(); it++) {
        os << *it << ' ';
    }
    os << '\n';
    return os;
}
 
int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::vector<int> vec;
        int k = 0;
        std::cin >> k;
        vec.push_back(1);
        vec.push_back(3);
        for (int j = 2; j < k;j++) {
            vec.push_back(vec[j-1]+2);
        }
        std::cout << vec;
    }
}
