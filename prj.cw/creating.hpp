#ifndef me
#define me

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class TestAPICreator {
private:
    static std::string extractFunctionName(const std::string& input);
    static std::string extractBetween(std::string& input);
    static std::string extractMethod(std::string& s);
public:
    static void create_test_api_files(std::string& text_file);
};

#endif
