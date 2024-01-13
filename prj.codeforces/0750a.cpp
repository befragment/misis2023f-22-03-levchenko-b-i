#include <iostream>

int main() {
    int needed_time = 0;

    int n, k = 0;
    std::cin >> n >> k;

    int time = 240 - k;
    int task = 0;

    for (int i = 1; i <= n; i++) {
        needed_time += 5 * i;
        if (time >= needed_time) {
            task += 1;
        }
    }
    std::cout << task << std::endl;
    return 0;
}
