#include "next_id.h"
#include "minunit.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE MAX_ID_LENGTH + 1
char *output;

void test_setup(void) {
	output = (char *)malloc(SIZE);
}

void test_teardown(void) {
	free(output);
}

MU_TEST(correct_strings) {
    next_id("B1", output, SIZE);
	mu_assert_string_eq("B2", output);
	
	next_id("B1-B1", output, SIZE);
	mu_assert_string_eq("B1-B2", output);
	
	next_id("C1", output, SIZE);
	mu_assert_string_eq("C2", output);
	
	next_id("D9", output, SIZE);
	mu_assert_string_eq("F1", output);
	
	next_id("Z9", output, SIZE);
	mu_assert_string_eq("B1-B1", output);
	
	next_id("Z9-D9", output, SIZE);
	mu_assert_string_eq("Z9-F1", output);
	
	next_id("B1-G3-B1-B1-Z9", output, SIZE);
	mu_assert_string_eq("B1-G3-B1-B2-B1", output);
	
	next_id("Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9", output, SIZE);
	mu_assert_string_eq("B1", output);
	
	next_id("X9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9", output, SIZE);
	mu_assert_string_eq("Z1-B1-B1-B1-B1-B1-B1-B1-B1-B1", output);
}
	
	
MU_TEST(incorrect_strings) {

    mu_check(next_id("smth", output, SIZE));
    mu_check(next_id("B", output, SIZE));
    mu_check(next_id("B1-A1-B1", output, SIZE));
    mu_check(next_id("B1+B1", output, SIZE));
    mu_check(next_id("B1-B1-", output, SIZE));
    mu_check(next_id("B1-BB", output, SIZE));
    mu_check(next_id("B1B1", output, SIZE));
}

MU_TEST(buffer_size) {
    int s;
    
    s = 0;                                  //недостаточный размер output
    output = (char *)realloc(output, s);
    mu_check(next_id("B1", output, s));
    
    s = 2;                                  //недостаточный размер output
    output = (char *)realloc(output, s);
    mu_check(next_id("B1", output, s));
    
    s = 3;                                  //OK
    output = (char *)realloc(output, s);
    mu_check(!next_id("B1", output, s));
    
    s = 20;                                 //OK
    output = (char *)realloc(output, s);
    mu_check(!next_id("B1", output, s));
    
    s = 4;                                  //переполнение output
    output = (char *)realloc(output, s);
    mu_check(next_id("Z9", output, s));
    
}


MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(correct_strings);
	MU_RUN_TEST(incorrect_strings);
	MU_RUN_TEST(buffer_size);

}

int main(int argc, char *argv[]) {
    
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
