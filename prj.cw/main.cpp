#include <iostream>
#include "creating.hpp"

int main() {
    std::string s = static_cast<std::string>(PRJROOT) + "/kk.cpp"; // my .cpp file with declarations
    TestAPICreator::create_test_api_files(s);
    return 0;
}
