#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[])
{

  MY_STRING hMy_String = NULL;
  MY_STRING hMy_String2 = NULL;
  Status test;

  hMy_String = my_string_init_default();
  hMy_String2 = my_string_init_default();

  string_print(hMy_String);

  string_print(hMy_String2);

  test = my_string_concat(hMy_String, hMy_String2);

  if (test == SUCCESS)
  {
	string_print(hMy_String);
  }

  my_string_destroy(&hMy_String);
  my_string_destroy(&hMy_String2);

  return 0;
}
