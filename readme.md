<h1>Задачи</h1>

<h2>Написание класса TestAPICreator</h2>

<p> 1. Класс TestAPICreator содержит методы, предназначенные для создания TestAPI файлов. </p>

```cpp
class TestAPICreator {
private:
    static std::string extractFunctionName(const std::string& input);
    static std::string extractBetween(std::string& input);
    static std::string extractMethod(std::string& s);
public:
    static void create_test_api_files(std::string& text_file);
};
```
---
https://github.com/bintest2023
