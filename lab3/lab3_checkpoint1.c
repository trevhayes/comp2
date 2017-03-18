#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[])
{

  MY_STRING hMy_String = NULL;

  FILE* fp;


  hMy_String = my_string_init_default();
  fp = fopen("simple.txt", "r");

  if (fp == NULL)
  {
	printf("Error opening file\n");
	exit(1);
  }

  while(my_string_extraction(hMy_String, fp))
  {
	my_string_insertion(hMy_String, stdout);
	printf("\n");
	if(fgetc(fp)==' ')
	{
		printf("Found a space after the string\n");
	}
  }

  my_string_destroy(&hMy_String);
  fclose(fp);

  return 0;
}
