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

<p>Основной метод нашего класса. В нем мы итерируемся по каждой строке c++ файла, с объявлением пользовательских функций. На вход мы получаем путь до .cpp файла. Далее, находим подстроку с названием метода или функции в каждой строке файла и генерируем новые с шаблонным именем, взятым из полученной подстроки.</p>
<p>Пример сгенерированного файла sub_testapi.cpp</p>

```cpp
// include header with your declarations here
int main() {
	// call int sub(int a, int b); here
	return 0;
}
```

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

<h2>2. Написание CMake скрипта, для последующего его интеграции в модуль FetchContent</h2>

<p>2.1. Определение архитектуры и операционной системы пользователя </p>

```cmake
set(FULL_SYSTEM_NAME "${ARCHITECTURE}-${OPERATING_SYSTEM}")
```

___

<p>2.2 Проверка на наличие тестового файла на клиенте, загрузка бинарного файла с тестами и main.cpp.o с кастомными репортами, написанных путем переопредения методов, описанных в различных классах doctest</p>

```cmake
set(main_file_url "${bintest}/test-binaries/raw/main/${FULL_SYSTEM_NAME}/main.cpp.o")
set(main_destination "${CMAKE_CURRENT_SOURCE_DIR}/objective/main.cpp.o")

# checking if required main_binary file exists otherwise we download it from git
if(EXISTS ${main_destination})
    message("-- ${binary_file} has been already downloaded")
else()
    file(DOWNLOAD ${main_file_url} ${main_destination} STATUS status)
    list(APPEND download_binaries ${main_destination})
endif()
```

___
<h2>3. Подготовка и модификация тестов, написанных с помощью doctest для библиотек из второго семестра, а именно, rational, matrixs, arrayd, arrayt</h2>

<h3>Ссылка на организацию bintest: https://github.com/bintest2023</h3>
