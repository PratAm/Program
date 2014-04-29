#include<stdio.h>
int main()
{
  char arr[5] = "geeks";  // arr[] is not terminated with '\0'
                                   // and its size is 5
  printf("%d", sizeof(arr));
  printf("%s", arr);
  getchar();
  return 0;
}
