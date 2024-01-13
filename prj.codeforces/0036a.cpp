#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
int main(){
    
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    
    std::vector<int>arr;
    for (int i = 0; i < n; i++){
        int k = 0;
        std::cin >> k;
        arr.push_back(k);
    }
    sort(arr.begin(), arr.end());
    
    for (int i = (n - 1); i >= 0; i--){
        if (k % arr[i] == 0){
            std::cout << k / arr[i] << std::endl;
            break;
        }
    }
    
    return 0;
}
