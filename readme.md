<h1>Задачи</h1>

<h2>1. Написание класса TestAPICreator</h2>

<p>Класс TestAPICreator содержит методы, предназначенные для создания TestAPI файлов. </p>

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
___

<p>Метод create_test_api_files</p>

```cpp
static void create_test_api_files(std::string& text_file);
```

<p>Основной метод нашего класса. В нем мы итерируемся по c++ файлу, с объявлением пользовательских функций. На вход мы получаем путь до .cpp файла. Далее, находим подстроку с названием метода или функции в каждой строке файла и создаем новые с шаблонным именем, описанным выше.</p>

___

<p> Метод extractMethod

```cpp
static std::string extractMethod(std::string& s);
```

<p>Метод, принимающий на вход название пользовательское объявление. Возвращает пустую строку, если она содержит функцию. Если же содержит метод, возвращает ИмяКласса::названиеМетода. </p>

___

<p>Метод extractFunctionName</p>

```cpp
static std::string extractFunctionName(const std::string& input);
```
<p>Метод, с помощью которого мы получаем название функции из ее объявления.</p>

___

<p>Метод extractBetween</p>

```cpp
static std::string extractMethod(std::string& s);
```

<p>Метод, с помощью которого мы получаем название метода из возвращенного значения из excractMethod ( находит подстроку между `::` и `(` ). </p>

___

<h2>2. Написание CMake скрипта, для последующего его включения в модуль FetchContent</h2>

```cmake
set(FULL_SYSTEM_NAME «${ARCHITECTURE}-${OPERATING_SYSTEM}")
```

https://github.com/bintest2023
