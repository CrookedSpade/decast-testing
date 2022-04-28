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
add_test(B1 next_id B1)
set_tests_properties(B1 PROPERTIES
PASS_REGULAR_EXPRESSION "B2")

add_test(B1-B1 next_id B1-B1)
set_tests_properties(B1-B1 PROPERTIES
PASS_REGULAR_EXPRESSION "B1-B2")

add_test(C1 next_id C1)
set_tests_properties(C1 PROPERTIES
PASS_REGULAR_EXPRESSION "C2")

add_test(D9 next_id D9)
set_tests_properties(D9 PROPERTIES
PASS_REGULAR_EXPRESSION "F1")

add_test(Z9 next_id Z9)
set_tests_properties(Z9 PROPERTIES
PASS_REGULAR_EXPRESSION "B1-B1")

add_test(Z9-D9 next_id Z9-D9)
set_tests_properties(Z9-D9 PROPERTIES
PASS_REGULAR_EXPRESSION "Z9-F1")

add_test(B1-G3-B1-B1-Z9 next_id B1-G3-B1-B1-Z9)
set_tests_properties(B1-G3-B1-B1-Z9 PROPERTIES
PASS_REGULAR_EXPRESSION "B1-G3-B1-B2-B1")

add_test(Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9 next_id Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9)
set_tests_properties(Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9 PROPERTIES
PASS_REGULAR_EXPRESSION "B1")

add_test(Z8-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9 next_id Z8-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9)
set_tests_properties(Z8-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9 PROPERTIES
PASS_REGULAR_EXPRESSION "Z9-B1-B1-B1-B1-B1-B1-B1-B1-B1")

add_test(something next_id something)
set_tests_properties(something PROPERTIES
PASS_REGULAR_EXPRESSION "incorrect input")

add_test(something next_id something)
set_tests_properties(something PROPERTIES
PASS_REGULAR_EXPRESSION "incorrect input")

add_test(B next_id B)
set_tests_properties(B PROPERTIES
PASS_REGULAR_EXPRESSION "ID is too short")

add_test(B1-A1-B1 next_id B1-A1-B1)
set_tests_properties(B1-A1-B1 PROPERTIES
PASS_REGULAR_EXPRESSION "incorrect input")

add_test(B1+B1 next_id B1+B1)
set_tests_properties(B1+B1 PROPERTIES
PASS_REGULAR_EXPRESSION "incorrect input")

add_test(B1-B1- next_id B1-B1-)
set_tests_properties(B1-B1- PROPERTIES
PASS_REGULAR_EXPRESSION "incorrect input")

add_test(B1-BB next_id B1-BB)
set_tests_properties(B1-BB PROPERTIES
PASS_REGULAR_EXPRESSION "incorrect input")

add_test(B1B1 next_id B1B1)
set_tests_properties(B1B1 PROPERTIES
PASS_REGULAR_EXPRESSION "incorrect input")
