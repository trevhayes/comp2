Status test_init_default_returns_nonNULL(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 if(hString == NULL)
 {
 	my_string_destroy(&hString);
 	strncpy(buffer, "test_init_default_returns_nonNULL\nmy_string_init_default returns NULL", length);
 	return FAILURE;
 }
 else
 {
 	my_string_destroy(&hString);
 	strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
 	return SUCCESS;
 }
}


Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_default();
 if(my_string_get_size(hString) != 0)
 {
 	status = FAILURE;
 	printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
 	strncpy(buffer, "test_get_size_on_init_default_returns_0\nDid not receive 0 from get_size after init_default\n", length);
 }
 else
 {
 	status = SUCCESS;
 	strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_get_capacity_on_init_default_returns_non0(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_default();
 if (my_string_get_capacity(hString) == 0)
 {
	status = FAILURE;
	printf("Expected capacity to not be zero; got capacity of %d\n", my_string_get_capacity(hString));
	strncpy(buffer, "test_thayes_get_capacity_on_init_default_returns_non0\nReceived 0 from get_capacity after init\n", length);
 }
 else
 {
	status = SUCCESS;
	strncpy(buffer, "test_thayes_get_capacity_on_init_default_returns_non0\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_handle_after_destroy_is_null(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_default();
 my_string_destroy(&hString);
 if (hString != NULL)
 {
	status = FAILURE;
	printf("Expected handle to be null after destruction\n");
	strncpy(buffer, "test_thayes_handle_after_destroy_is_null\nHandle not null\n", length);
 }
 else
 {
	status = SUCCESS;
	strncpy(buffer, "test_thayes_handle_after_destroy_is_null\n", length);
 }
 return status;
}


Status test_thayes_non_empty_string_after_init_c_string(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_c_string("test");
 Boolean empty = my_string_empty(hString);
 if (empty == TRUE)
 {
	status = FAILURE;
	printf("Expected string to be non-empty\n");
	strncpy(buffer, "test_thayes_non_empty_string_after_init_c_string\nString empty\n", length);
 }
 else
 {
	status = SUCCESS;
	strncpy(buffer, "test_thayes_non_empty_string_after_init_c_string\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_nonzero_size_after_init_c_string(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_c_string("test");
 if (my_string_get_size(hString) == 0)
 {
	status = FAILURE;
	printf("Expected size to be nonzero\n");
	strncpy(buffer, "test_thayes_nonzero_size_after_init_c_string\nSize is zero\n", length);
 }
 else
 {
	status = SUCCESS;
	strncpy(buffer, "test_thayes_nonzero_size_after_init_c_string\n", length);
 }
 my_string_destroy(hString);
 return status;
}


Status test_thayes_nonzero_capacity_after_init_c_string(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_c_string("test");
 if (my_string_get_capacity(hString) == 0)
 {
	status = FAILURE;
	printf("Expected capacity to be nonzero\n");
	strncpy(buffer, "test_thayes_nonzero_capacity_after_init_c_string\nCapacity is zero\n", length);
 }
 else
 {
	status = SUCCESS;
	strncpy(buffer, "test_thayes_nonzero_capacity_after_init_c_string\n", length);
 }
 my_string_destroy(hString);
 return status;
}


Status test_thayes_init_c_string_returns_nonNULL(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_c_string("test");
 if(hString == NULL)
 {
 	my_string_destroy(&hString);
 	strncpy(buffer, "test_thayes_init_c_string_returns_nonNULL\nmy_string_init_c_string returned NULL", length);
 	return FAILURE;
 }
 else
 {
 	my_string_destroy(&hString);
 	strncpy(buffer, "\ttest_thayes_init_c_string_returns_nonNULL\n", length);
 	return SUCCESS;
 }
}


Status test_thayes_string_extraction_returns_success(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 FILE * fp = "test.txt";
 Status status = my_string_extraction(hString, fp);
 if (status == FAILURE)
 {
	printf("Expected capacity to be nonzero\n");
	strncpy(buffer, "test_thayes_string_extraction_returns_success\nExtraction failed\n", length);
 }
 else
 {
	strncpy(buffer, "test_thayes_string_extraction_returns_success\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_empty_string_insertion_returns_failure(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();

 Status status = my_string_insertion(hString, stdout);
 if (status == SUCCESS)
 {
	printf("Expected insertion to fail\n");
	strncpy(buffer, "test_thayes_empty_string_insertion_returns_failure\nInsertion not supposed to be successful\n", length);
	my_string_destroy(&hString);
	return FAILURE;
 }
 else
 {
	strncpy(buffer, "test_thayes_empty_string_insertion_returns_failure\n", length);
	my_string_destroy(&hString);
	return SUCCESS;
 }
}


Status test_thayes_string_insertion_returns_success(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_c_string("hello");

 Status status = my_string_insertion(hString, stdout);
 if (status == FAILURE)
 {
	printf("Expected insertion to succeed\n");
	strncpy(buffer, "test_thayes_string_insertion_returns_success\nInsertion failed\n", length);
 }
 else
 {
	strncpy(buffer, "test_thayes_string_insertion_returns_success\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_my_string_empty_returns_true(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 Boolean isEmpty = my_string_empty(hString);

 if (isEmpty == FALSE)
 {
	printf("Expected function to return true\n");
	strncpy(buffer, "test_thayes_string_insertion_returns_success\nReturned false\n", length);
	my_string_destroy(&hString);
	return FAILURE;
 }
 else
 {
	strncpy(buffer, "test_thayes_my_string_empty_returns_true\n", length);
	my_string_destroy(&hString);
	return SUCCESS;
 }
}


Status test_thayes_my_string_empty_returns_false(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_c_string("string_not_empty");
 Boolean isEmpty = my_string_empty(hString);

 if (isEmpty == TRUE)
 {
	printf("Expected function to return false\n");
	strncpy(buffer, "test_thayes_my_string_empty_returns_false\nReturned true\n", length);
	my_string_destroy(&hString);
	return FAILURE;
 }
 else
 {
	strncpy(buffer, "test_thayes_my_string_empty_returns_false\n", length);
	my_string_destroy(&hString);
	return SUCCESS;
 }
}


Status test_thayes_string_not_empty_after_push(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 Status status;
 Boolean isEmpty;
 my_string_push_back(hString, 'z');
 isEmpty = my_string_empty(hString);
 if (isEmpty == TRUE)
 {
	printf("Expected function to return false\n");
	strncpy(buffer, "test_thayes_string_not_empty_after_push\nReturned true\n", length);
	status = FAILURE;
 }
 else
 {
	strncpy(buffer, "test_thayes_my_string_empty_returns_false\n", length);
	status = SUCCESS;
 }

 my_string_destroy(&hString);
 return status;
}


Status test_thayes_realloc_when_pushing_into_full_string_success(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 Status status;

 while (my_string_get_size(hString) <= my_string_get_capacity(hString))
 {
	my_string_push_back(hString, 'z');
 }
 
 status = my_string_push_back(hString, 'a');
 if (status == FAILURE)
 {
	printf("Expected success\n");
	strncpy(buffer, "test_thayes_realloc_when_pushing_into_full_string_success\nReturned failure\n", length);
 }
 else
 {
	strncpy(buffer, "test_thayes_realloc_when_pushing_into_full_string_success\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_push_success(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 Status status = my_string_push_back(hString, 'a');
 if (status == FAILURE)
 {
	printf("Expected success\n");
	strncpy(buffer, "test_thayes_push_success\nReturned failure\n", length);
 }
 else
 {
	strncpy(buffer, "test_thayes_push_success\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_pop_success(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_c_string("abc");
 Status status = my_string_pop_back(hString);
 if (status == FAILURE)
 {
	printf("Expected success\n");
	strncpy(buffer, "test_thayes_pop_success\nReturned failure\n", length);
 }
 else
 {
	printf("Expected success\n");
	strncpy(buffer, "test_thayes_pop_success\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_size_increase_after_push(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 int oldSize = my_string_get_size(hString);
 my_string_push_back(hString, 'a');
 if (oldSize == my_string_get_size(hString))
 {
	printf("Expected size to increase\n");
	strncpy(buffer, "test_thayes_size_increase_after_push\nSize did not increase\n", length);
	my_string_destroy(&hString);
	return SUCCESS;
 }
 else
 {
	strncpy(buffer, "test_thayes_size_increase_after_push\n", length);
	my_string_destroy(&hString);
	return SUCCESS;
 }

}


Status test_thayes_size_decrease_after_pop(char* buffer, int length)
{
 Status status;
 MY_STRING hString = NULL;
 hString = my_string_init_c_string("abc");
 int oldSize = my_string_get_size(hString);
 my_string_pop_back(hString);
 if (oldSize == my_string_get_size(hString))
 {
	status = FAILURE;
	printf("Expected size to decrease\n");
	strncpy(buffer, "test_thayes_size_decrease_after_pop\nSize did not decrease\n", length);
 }
 else
 {
	status = SUCCESS;
	strncpy(buffer, "test_thayes_size_decrease_after_pop\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_string_at_negative_index_returns_NULL(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_c_string("test");
 Status status;
 char * ch;
 ch = my_string_at(hString, -1);
 if (ch != NULL)
 {
	status = FAILURE;
	printf("Expected the returned character pointer to be NULL\n");
	strncpy(buffer, "test_thayes_string_at_negative_index_returns_NULL\npointer is not NULL\n", length);
 }
 else
 {
	status = SUCCESS;
	strncpy(buffer, "test_thayes_string_at_negative_index_returns_NULL\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_string_at_zero_size_returns_NULL(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 char * ch;
 ch = my_string_at(hString, 0);
 Status status;
 if (ch != NULL)
 {
	status = FAILURE;
	printf("Expected the returned character pointer to be NULL\n");
	strncpy(buffer, "test_thayes_string_at_negative_index_returns_NULL\npointer is not NULL\n", length);
 }
 else
 {
	status = SUCCESS;
	strncpy(buffer, "test_thayes_string_at_negative_index_returns_NULL\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_string_at_correct_usage_returns_nonNULL(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_c_string("123");
 Status status;
 char * ch;
 ch = my_string_at(hString, 1);
 if (ch == NULL)
 {
	status = FAILURE;
	printf("Expected the returned character pointer to be non-NULL\n");
	strncpy(buffer, "test_thayes_string_at_correct_usage_returns_NULL\npointer is NULL\n", length);
 }
 else
 {
	status = SUCCESS;
	strncpy(buffer, "test_thayes_string_at_correct_usage_returns_NULL\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_string_concat_success(char* buffer, int length)
{
 MY_STRING hString1 = NULL;
 MY_STRING hString2 = NULL;
 hString1 = my_string_init_c_string("123");
 hString2 = my_string_init_c_string("456");
 Status status = my_string_concat(hString1, hString2);
 if (status == FAILURE)
 {
	printf("Expected string concat to be successful\n");
	strncpy(buffer, "test_thayes_string_concat_success\nConcat failed\n", length);
 }
 else
 {
	strncpy(buffer, "test_thayes_string_concat_success\n", length);
 }
 my_string_destroy(&hString1);
 my_string_destroy(&hString2);
 return status;
}


Status test_thayes_string_print_success(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_c_string("test\n");
 Status status = string_print(hString);
 if (status == FAILURE)
 {
	printf("Expected print function to be successul\n");
	strncpy(buffer, "test_thayes_string_print_success\nPrint failed\n", length);
 }
 else
 {
	strncpy(buffer, "test_thayes_string_print_success\n", length);
 }
 my_string_destroy(&hString);
 return status;
}


Status test_thayes_string_compare_success(char* buffer, int length)
{
 MY_STRING hString1 = NULL;
 MY_STRING hString2 = NULL;
 hString1 = my_string_init_c_string("asdf");
 hString2 = my_string_init_c_string("asdf");
 Status status;
 int check = my_string_compare(hString1, hString2);
 if (check != 0)
 {
	status == FAILURE;
	printf("Expected the strings to be found as the same\n");
	strncpy(buffer, "test_thayes_string_compare_success\nComparison failed\n", length);
 }
 else
 {
	status == SUCCESS;
	strncpy(buffer, "test_thayes_string_compare_success\n", length);
 }
 my_string_destroy(&hString1);
 my_string_destroy(&hString2);
 return status;
}


