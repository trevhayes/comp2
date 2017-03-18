#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

typedef struct MY_STRING myString;


struct myString {

	int size;
	int capacity;
	char* charPointer;

};
typedef struct myString MyString;
MY_STRING my_string_init_default(void) {

	MyString* pString;

	pString = (MyString*) malloc(sizeof(MyString));

	pString->charPointer = (char*) malloc(sizeof(char)*7);

	if (pString == NULL) {		
		return NULL;		
	}

	else {
		pString->size=0;
		pString->capacity=7;
	}
	return pString;
}

void my_string_destroy(MY_STRING* phMy_String) {

	MyString* pString = (MyString*) *phMy_String;

	free(pString->charPointer);

	free(pString);

	*phMy_String = NULL;

}

MY_STRING my_string_init_c_string(const char* c_string)
{

	MyString* inputString = (MyString*) malloc(sizeof(MyString));
	int numOfChars = 0, x = 0;
	char c = '\0';
	
	if (c_string == NULL)
	{
		free(inputString); //if c_string is null, free the local MyString object
	}

	c = c_string[0];

	while (c != '\0')
	{
		numOfChars++;
		c = c_string[numOfChars];
	}
	inputString->size = numOfChars;
	inputString->capacity = numOfChars + 1;
	inputString->charPointer = (char*) malloc(sizeof(char)*inputString->capacity);

	while (x < inputString->capacity)
	{
		inputString->charPointer[x] = c_string[x];
		x++;
	}
	return inputString;

}

int my_string_get_capacity(MY_STRING hMy_string)
{
	return ((MyString*)hMy_string)->capacity;
}


int my_string_get_size(MY_STRING hMy_string)
{
	return ((MyString*)hMy_string)->size;//pString->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{

	MyString* left = (MyString*) hLeft_string;
	MyString* right = (MyString*) hRight_string;

	int a = 0;

	while (left->charPointer[a] != '\0')
	{
		if (right->charPointer[a] == '\0')
		{
			return 1;
		}
		if (left->charPointer[a] < right->charPointer[a])
		{
			return -1;
		}
		if (left->charPointer[a] == right->charPointer[a])
		{
			//empty
		}
		a++;
	}
	if (right->charPointer[a] == '\0')
	{
		return 0; //if the right string ends at the same time as the left, then return 0
	}

}
