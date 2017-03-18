#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_thayes_get_capacity_on_init_default_returns_non0(char* buffer, int length);
Status test_thayes_handle_after_destroy_is_null(char* buffer, int length);
Status test_thayes_non_empty_string_after_init_c_string(char* buffer, int length);
Status test_thayes_nonzero_size_after_init_c_string(char* buffer, int length);
Status test_thayes_nonzero_capacity_after_init_c_string(char* buffer, int length);
Status test_thayes_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_thayes_string_extraction_returns_success(char* buffer, int length);
Status test_thayes_empty_string_insertion_returns_failure(char* buffer, int length);
Status test_thayes_string_insertion_returns_success(char* buffer, int length);
Status test_thayes_my_string_empty_returns_true(char* buffer, int length);
Status test_thayes_my_string_empty_returns_false(char* buffer, int length);
Status test_thayes_string_not_empty_after_push(char* buffer, int length);
Status test_thayes_realloc_when_pushing_into_full_string_success(char* buffer, int length);
Status test_thayes_push_success(char* buffer, int length);
Status test_thayes_pop_success(char* buffer, int length);
Status test_thayes_size_increase_after_push(char* buffer, int length);
Status test_thayes_size_decrease_after_pop(char* buffer, int length);
Status test_thayes_string_at_negative_index_returns_NULL(char* buffer, int length);
Status test_thayes_string_at_zero_size_returns_NULL(char* buffer, int length);
Status test_thayes_string_at_correct_usage_returns_nonNULL(char* buffer, int length);
Status test_thayes_string_concat_success(char* buffer, int length);
Status test_thayes_string_print_success(char* buffer, int length);
Status test_thayes_string_compare_success(char* buffer, int length);

#endif
