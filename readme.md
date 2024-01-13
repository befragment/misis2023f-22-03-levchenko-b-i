<h1>Задачи</h1>

<h2>1. Написание класса TestAPICreator</h2>

<p>1.1 Класс TestAPICreator содержит методы, предназначенные для создания TestAPI файлов. </p>

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

<p>1.2. Метод create_test_api_files</p>

```cpp
static void create_test_api_files(std::string& text_file);
```

<p>Основной метод нашего класса. В нем мы итерируемся по c++ файлу, с объявлением пользовательских функций. На вход мы получаем путь до .cpp файла. Далее, находим подстроку с названием метода или функции в каждой строке файла и создаем новые с шаблонным именем, описанным выше.</p>

___

<p>1.3. Метод extractMethod

```cpp
static std::string extractMethod(std::string& s);
```

<p>Метод, принимающий на вход название пользовательское объявление. Возвращает пустую строку, если она содержит функцию. Если же содержит метод, возвращает ИмяКласса::названиеМетода. </p>

___

<p>1.4. Метод extractFunctionName</p>

```cpp
static std::string extractFunctionName(const std::string& input);
```
<p>Метод, с помощью которого мы получаем название функции из ее объявления.</p>

___

<p>1.5. Метод extractBetween</p>

```cpp
static std::string extractMethod(std::string& s);
```

<p>Метод, с помощью которого мы получаем название метода из возвращенного значения из excractMethod ( находит подстроку между `::` и `(` ). </p>

___

<h2>2. Написание CMake скрипта, для последующего его включения в модуль FetchContent</h2>

<p>2.1. Определение архитектуры и операционной системы пользователя </p>

```cmake
set(FULL_SYSTEM_NAME «${ARCHITECTURE}-${OPERATING_SYSTEM}")
```

___

<p>2.2 Проверка на наличие тестового файла на клиенте.</p>

```cmake
if(EXISTS ${destination})
    message("-- ${binary_file} has been already downloaded")
else()
    file(DOWNLOAD ${file_url} ${destination} STATUS status)
    list(APPEND download_binaries ${destination})
endif()
```

___



https://github.com/bintest2023
