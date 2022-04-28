# Задать минимальную версию CMake:
cmake_minimum_required(VERSION 3.8)

# Указать характеристики проекта:
project(decast_testing)

# Добавить в сборку исполняемый файл "MyProgram":
add_executable(next_id next_id.c)

# Установить исполняемый файл в директорию "bin":
install(TARGETS next_id DESTINATION bin)

enable_testing()

# Добавить тесты:
add_test(FirstTest next_id B2-Z9)

set_tests_properties(FirstTest PROPERTIES
PASS_REGULAR_EXPRESSION "B2-B1")