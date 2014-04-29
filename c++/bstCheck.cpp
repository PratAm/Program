#include<iostream>
#include<queue>

using namespace std;

string checkBST(int *a,int a_size,int *b,int b_size)
{
  string fail = "FAILURE";
  string success = "SUCCESS";
  queue<int> lessThanRoot;
  queue<int> greaterThanRoot;

 	if(a[0] != b[0] or a_size != b_size) return fail;
  
  int root = a[0];

  for(int i =1;i <a_size;++i)
  { 
    if(a[i] < root)
    {
      lessThanRoot.push(a[i]);
    }else
    {
      greaterThanRoot.push(a[i]);
    }
  }
     
  for(int i =1;i <b_size;++i)
  { 
    if(b[i] < root)
    {
      if(b[i] !=lessThanRoot.front()) return fail;
      lessThanRoot.pop();
    }else
    {
      if(b[i] != greaterThanRoot.front()) return fail;
      greaterThanRoot.pop();
    }
  }

 return success;
}
  

int main()
{
 int a[9] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
 int b[9] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
 
 
 cout<<"Result :" << checkBST(a,9,b,9) <<endl;
 return 0;
}
