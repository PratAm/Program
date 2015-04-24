
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5
#define false 0
#define true 1

// Function to print matrix arr[N][N]
void printMatrix(int **arr)
{
 int i,j;
 printf("\n\n");
 for (i = 0; i < N; i++)
 {
  for (j = 0; j < N; j++)
   printf(" %d ", arr[i][j]);
  printf("\n");
 }
}

int isValidIndexes(int currrow,int currcol)
{
 if(currrow>=0 && currrow < N && currcol>=0 && currcol<N)
  return true;
 else
  return false;
}

/* A recursive utility function to solve search problem in all 8 side (including diagonal sides) */
int search_rec(char arr[][N], int currrow, int currcol,int **used,char *str,int len,int index)
{
 int i,j,ret=0;

 // CASE 1: when going beyond last char to search
 if(index == len)
 {
  printMatrix(used);
  return true;//solve successfully
 }

 //CASE 2: out-of-bound check
 if(!isValidIndexes(currrow,currcol))
 {
  return false;
 }

 //CASE 3 : if we encounter already used cell, NOT ALLOWD , so return false
 if(used[currrow][currcol] == 1 )
 {
  return false;
 }
 //CASE 4 : CRITICAL ... WE CAN ONLY GO FOR 8 NEIGHBOUR SEARCH , ONCE WE FOUND FIRST INDEX
 if(arr[currrow][currcol]!=str[index] && index ==0) //for 0th index search
 {
  //CASE 4.1 : search same index on same row for next col
  if(currcol != N-1)
   return search_rec(arr,currrow,currcol+1,used,str,len,index);//right adjecent element
  //CASE 4.2 : search same index on next row staring from zero col
  else if(currrow != N-1)
   return search_rec(arr,currrow+1,0,used,str,len,index);//next row element
  //CASE 4.3 : 0th index itself not exist any where
  else
   return false;
 }

 //CASE 5 : check for current element match current index of str
 if(arr[currrow][currcol] == str[index])
 {
  used[currrow][currcol] = 1; //marking as used match
  //CASE 5.1: index match, so now try all possible remaining 8 neighbours

  ret =  search_rec(arr,currrow,currcol-1,used,str,len,index+1) //left adjecent element
   || search_rec(arr,currrow,currcol+1,used,str,len,index+1)//right adjecent element
   || search_rec(arr,currrow-1,currcol,used,str,len,index+1)//upper adjecent element
   || search_rec(arr,currrow+1,currcol,used,str,len,index+1)//lower adjecent element
   || search_rec(arr,currrow+1,currcol-1,used,str,len,index+1)//left-lower diagonal element
   || search_rec(arr,currrow+1,currcol+1,used,str,len,index+1)//right-lower diagonal element
   || search_rec(arr,currrow-1,currcol-1,used,str,len,index+1)//left-upper diagonal element
   || search_rec(arr,currrow-1,currcol+1,used,str,len,index+1);//right-upperdiagonal element

  used[currrow][currcol] = 0; //reset again... backtrack

  return ret; // it will be true if next index found in any of 8 adjecent element

 }
 else
 {
  //CASE 5.2: index doen't match
  return false;
 }

}

void searchstr(char arr[N][N],int row,int col, char *str,int len)
{
 // we need to maintain which element are (1) taken and (2) which element we are not taken
 // all these detail can be maintain in USED array of same size

 int **used = (int **)malloc(sizeof(int *) * N);

 int i,j;

 for(i=0;i<N;i++)
 {
  used[i] = (int *)malloc(sizeof(int) * N);
  for(j=0;j<N;j++)
  {
   used[i][j] = 0;
  }
 }
 int start_index=0;

 //initial call would start from 0,0
 if(search_rec(arr,0,0,used,str,len,start_index))
 {
  printf("\nWord [%s] found.\n",str);
 }
 else
 {
  printf("\nWord [%s] not found.\n",str);
 }

 //free allocated memory
 for(i=0;i<N;i++)
 {
  free(used[i]);
 }
 free(used);
}


int main()
{
    char arr[N][N] = {
  'A','C','P','R','C',
  'X','S','O','P','C',
  'V','O','V','N','I',
  'W','G','F','M','N',
  'Q','A','T','I','T'
 };

 char str[] = "MICROSOFT";
 searchstr(arr,5,5,str,strlen(str));

 return 0;
}

