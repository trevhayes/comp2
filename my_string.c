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

	pString->charPointer = (char*) malloc(sizeof(char)*26);

	if (pString == NULL) {		
		return NULL;		
	}

	else {
		pString->size=0;
		pString->capacity=26;
		for (int i = 0; i < 26; i++)
		{
			pString->charPointer[i] = '\0';
		}
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
	while (a < left->size)
	{

		if (right->charPointer[a] == NULL)
		{
			return 1;
		}

		if (left->charPointer[a] < right->charPointer[a])
		{
			return -1;
		}
		if (left->charPointer[a] > right->charPointer[a])
		{
			return 1;
		}
		if (left->charPointer[a] == right->charPointer[a])
		{} //do nothing yet
	}

	return 0; //if the function gets this far, then return 0

}


Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	
	char str[50];
	char c; 
	int i = 0;
	
	MyString* pString = (MyString*) hMy_string;
	
	if (fp == NULL)
	{
		return FAILURE;
	}

	pString->size = 0;
	for (int x = 0; x < 50; x++)
	{ //clear out pString->charPointer to avoid keeping unwanted chars
		pString->charPointer[x] = '\0';
	}
	
	c = fgetc(fp);

	if (c == EOF)
	{
		return FAILURE;
	}

	while (c != EOF && c != '\n')
	{
/*
		if (c != ' ')
		{
			str[i] = c;
			i++;
			pString->size++;
			c = fgetc(fp);
		}
		else if (c == ' ')
		{
			str[i] = c;
			ungetc(' ', fp);
			break;
		}
*/

		str[i] = c;
		i++;
		pString->size++;
		c = fgetc(fp);
		
	
	}

	if (c == '\n')
	{
		str[i] = c;
		str[i+1] = '\0';
	}

	i = 0;
/*
	while (str[i] != ' ')
	{
		pString->charPointer[i] = str[i];
		i++;
	}
*/

	while (str[i] != '\0')
	{
		pString->charPointer[i] = str[i];
		i++;
	}

	return SUCCESS;
}


Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	MyString* pString = (MyString*) hMy_string;
	int i = 0;

	if (pString == NULL)
	{
		printf("Error with my_string_insertion.\n");
		return FAILURE;
	}

	if (pString->charPointer[5] == '\n')
	//it's set to find if element 5 is holding a newline character
	//changing the 5 to 29 will return the words that are 29 chars long
	//the only word in the list with 29 letters is floccinaucinihilipilification
	{
		while (pString->charPointer[i] != '\0')
		{
			fprintf(stdout, "%c", pString->charPointer[i]);
			i++;
		}
	}
	else
	{
		return FAILURE;
	}

	return SUCCESS;
}


Status my_string_push_back(MY_STRING hMy_string, char item)
{
	MyString* pString = (MyString*) hMy_string;
	if (pString->size == pString->capacity)
	{
		pString->capacity *= 2;
		pString->charPointer = (char*) realloc(pString->charPointer, sizeof(char)*pString->capacity);

		if (pString->charPointer == NULL) {		
			return FAILURE;	//not enough memory to reallocate, return failure	
		}
	}

	if (pString->size < pString->capacity)
	{

		//MyString* pString = (MyString*) hMy_string;
		int space = pString->size+1;
		pString->charPointer[space] = item;

		pString->size++;
		return SUCCESS; //pushing was a success
	}
		


	return FAILURE; //if the function gets this far, then return FAILURE
}



Status my_string_pop_back(MY_STRING hMy_string)
{
	MyString* pString = (MyString*) hMy_string;
	
	if (pString->size == 0)
	{
		return FAILURE; //string is empty, return failure
	}


	pString->size--;
	pString->charPointer[pString->size] = '\0'; //set the new end of string equal to null


	
	return SUCCESS;
}


char* my_string_at(MY_STRING hMy_string, int index)
{

	MyString* pString = (MyString*) hMy_string;
	if (index >= pString->size || index < 0)
	{
		return NULL; //index is greater than the current size of the string
	}

	return &pString->charPointer[index];
	
}


char* my_string_c_str(MY_STRING hMy_string)
{
	MyString* pString = (MyString*) hMy_string;
	char * cString;

	cString = pString->charPointer[0]; //get the address at charPointer[0]
	return cString; 
	
}

Status string_print(MY_STRING hMy_string)
{

	MyString* pString = (MyString*) hMy_string;
	
	int x=0;

	while (x < pString->size)
	{
		printf("%c", *my_string_at(pString, x)); //pointer to a function
		x++;
	}
	printf("\n");

	return SUCCESS;
}


Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
	int x = 0;

	MyString* phResult = (MyString*) hResult;
	MyString* phAppend = (MyString*) hAppend;

	if ((phResult->size + phAppend->size) > phResult->capacity)
	{
		phResult->capacity *= 2;
		phResult->charPointer = (char*) realloc(phResult->charPointer, sizeof(char)*phResult->capacity);
		if (phResult->charPointer == NULL)
		{
			return FAILURE; //realloc failed, return failure
		}
	}


	while (x <= phAppend->size)
	{
		phResult->charPointer[phResult->size] = phAppend->charPointer[x];
		x++;
		phResult->size++;
	}

	return SUCCESS;
}



Boolean my_string_empty(MY_STRING hMy_string)
{
	MyString* pString = (MyString*) hMy_string;

	if (pString->size == 0)
	{
		return TRUE;
	}

	else return FALSE;
}
