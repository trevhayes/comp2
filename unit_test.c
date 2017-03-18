#include <stdio.h>
#include "unit_test.h"


//The main creates an array of function pointers where
//every function pointer will hold the address of a test function
//which has the following signature:
//
//   Status long_function_name(char* buffer, int length);


int main(int argc, char* argv[])
{
 Status (*tests[])(char*, int) =
 {
 	test_init_default_returns_nonNULL,
 	test_get_size_on_init_default_returns_0,
	test_thayes_get_capacity_on_init_default_returns_non0,
	test_thayes_handle_after_destroy_is_null,
	test_thayes_non_empty_string_after_init_c_string,
	test_thayes_nonzero_size_after_init_c_string,
	test_thayes_nonzero_capacity_after_init_c_string,
	test_thayes_init_c_string_returns_nonNULL,
	test_thayes_string_extraction_returns_success,
	test_thayes_empty_string_insertion_returns_failure,
	test_thayes_string_insertion_returns_success,
	test_thayes_my_string_empty_returns_true,
	test_thayes_my_string_empty_returns_false,
	test_thayes_string_not_empty_after_push,
	test_thayes_realloc_when_pushing_into_full_string_success,
	test_thayes_push_success,
	test_thayes_pop_success,
	test_thayes_size_increase_after_push,
	test_thayes_size_decrease_after_pop,
	test_thayes_string_at_negative_index_returns_NULL,
	test_thayes_string_at_zero_size_returns_NULL,
	test_thayes_string_at_correct_usage_returns_nonNULL,
	test_thayes_string_concat_success,
	test_thayes_string_print_success,
	test_thayes_string_compare_success
 };
 int number_of_functions = sizeof(tests) / sizeof(tests[0]);
 int i;
 char buffer[500];
 int success_count = 0;
 int failure_count = 0;
 for(i=0; i<number_of_functions; i++)
 {
 	if(tests[i](buffer, 500) == FAILURE)
 	{
 		printf("FAILED: Test %d failed miserably\n", i);
 		printf("\t%s\n", buffer);
 		failure_count++;
 	}
 	else
 	{
		// printf("PASS: Test %d passed\n", i);
		// printf("\t%s\n", buffer);
 		success_count++;
 	}
 }
 printf("Total number of tests: %d\n", number_of_functions);
 printf("%d/%d Pass, %d/%d Failure\n", success_count,
 number_of_functions, failure_count, number_of_functions);
 return 0;
}
