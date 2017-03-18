#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[])
{

  MY_STRING hMy_String = NULL; //left string
  MY_STRING hMy_String2 = NULL; //right string

  //hMy_String = my_string_init_default();

  hMy_String = my_string_init_c_string("hi");

  hMy_String2 = my_string_init_c_string("hello");

  int z = my_string_compare(hMy_String, hMy_String2);

  if (z < 0)
  {
	printf("The left string is smaller than the right string.\n");
  } else if (z == 0)
  {
	printf("The two strings are equal in size.\n");
  } else if (z > 0)
  {
	printf("The right string is smaller than the left string.\n");
  }

  my_string_destroy(&hMy_String);
  my_string_destroy(&hMy_String2);

  return 0;
}
