#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

  int array[20][30];
  
  printf("Hello world! I have created a dynamic 2D-array of 20x30 integers!\n");

  int number = 0;

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 30; j++) {
      array[i][j] = j + number;
      printf("%3d", array[i][j]);
    }
    printf("\n");
    number++;
  }
  
  return 0;
}
