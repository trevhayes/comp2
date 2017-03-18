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

	pString->charPointer = (char*) malloc(sizeof(char)*50);

	if (pString == NULL) {		
		return NULL;		
	}

	else {
		pString->size=0;
		pString->capacity=50;
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

/* int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
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


} */


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
