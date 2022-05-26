# Задать минимальную версию CMake:
cmake_minimum_required(VERSION 3.8)

# Указать характеристики проекта:
project(decast_testing)

set(SOURCES test.c next_id.c)

# Добавить в сборку исполняемый файл:
add_executable(testapp ${SOURCES})

enable_testing()

# Добавить тесты:
add_test(1 testapp)
