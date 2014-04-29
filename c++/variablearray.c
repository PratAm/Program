#include<stdio.h>
 
int main()
{
  int M = 2;
  int arr[M][M];
  int i, j;
  for (i = 0; i < M; i++)
  {
    for (j = 0; j < M; j++)
    {
       arr[i][j] = 0;
       printf ("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
