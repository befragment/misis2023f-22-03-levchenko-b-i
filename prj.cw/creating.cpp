#include "creating.hpp"

std::string TestAPICreator::extractFunctionName(const std::string& input) {
    size_t start = input.find('(');

    if (start != std::string::npos) {
        size_t lastSpace = input.rfind(' ', start);

        if (lastSpace != std::string::npos) {
            return input.substr(lastSpace + 1, start - lastSpace - 1);
        }
    }

    return "";
}

std::string TestAPICreator::extractBetween(std::string& input){
    size_t start = input.find("::");
    size_t end = input.find('(', start);

    if (start != std::string::npos && end != std::string::npos && end > start + 2) {
        return input.substr(start + 2, end - start - 2);
    }

    return "";
}

std::string TestAPICreator::extractMethod(std::string& s) {
    std::string meth;
    size_t start = s.find("::");
    size_t end = s.find('(', start);
    if (s.find("::") != std::string::npos) {
        if (start != std::string::npos && end != std::string::npos && end > start + 2) {
            meth = s.substr(start + 2, end - start - 2);
        }
    } else {
        return "";
    }
    return meth;
}

void TestAPICreator::create_test_api_files(std::string& text_file) {
    std::ifstream inputFile(text_file);

    if (!inputFile.is_open()) {
        throw std::ifstream::failure("check " + text_file + " once again");
    }

    std::string function_name;
    while (std::getline(inputFile, function_name)) {
        // in CMakeLists.txt : add_definitions(-DPRJROOT="${CMAKE_CURRENT_SOURCE_DIR}")

        if (function_name[0] == '#' || function_name[0] == ' ' || function_name.empty()) {
            continue;
        }

        if (function_name.compare(0, 5, "class") == 0 ||
            function_name.find("static") != std::string::npos ||
            function_name.find("constexpr") != std::string::npos) {
            throw std::invalid_argument("check the documentation!");
        }

        std::string test_api_filename;
        std::string test_api_name;

        if (!extractMethod(function_name).empty()) {
            test_api_name = extractBetween(function_name);
            test_api_filename = static_cast<std::string>(PRJROOT)
                                + "/" + test_api_name + "_testapi.cpp";
        } else {
            test_api_name = extractFunctionName(function_name);
            test_api_filename = static_cast<std::string>(PRJROOT)
                                + "/" + test_api_name + "_testapi.cpp";
            std::cout << test_api_filename << std::endl;
        }


        std::ofstream test_api_file(test_api_filename);

        if (!test_api_file.is_open()) {
            std::cerr << "Unexpected error occurred while creating " << test_api_filename << std::endl;
        }


        test_api_file << "// include header with your declarations here\n"
                      << "int main() {\n"
                      << "\t" << "// call " << function_name <<" here" << "\n"
                      << "\treturn 0;\n"
                      << '}';

        test_api_file.close();
    }
    inputFile.close();
}
