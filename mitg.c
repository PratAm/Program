#include <stdio.h>

int array[] = {1,2,3,4,5,6,7};
#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))
 
int main(void)
{
  int c;
 
  for(c = -1;c <= (int)(TOTAL_ELEMENTS - 2); c++)
  {
    printf("%d\n",array[c+1]);
  }
  return 0;
}
