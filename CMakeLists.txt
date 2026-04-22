cmake_minimum_required(VERSION 3.10)
project(NumberProject)

set(CMAKE_CXX_STANDARD 17)

# --- Додавання Google Test через FetchContent ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Налаштування, щоб не збирати зайве
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- Бібліотека з нашою логікою ---
# Це дозволяє не дублювати код для main та для тестів
add_library(LogicLib Number.cpp Real.cpp)

# --- Основна програма ---
add_executable(main_app main.cpp)
target_link_libraries(main_app LogicLib)

# --- Юніт-тести ---
add_executable(unit_tests UnitTest.cpp)
target_link_libraries(unit_tests LogicLib gtest_main) # gtest_main сам додає точку входу main() для тестів

# Дозволяє запускати тести через команду 'ctest'
enable_testing()
add_test(NAME MyTests COMMAND unit_tests)