#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int generateNo(long long int num,long long int &in)
{
    if(num > INT_MAX)
     return -1;
    if(num%in ==0){
      cout << num << endl;
      return 1;
    }
    long long num1 = num*10;
    if(num1%in ==0){
      cout << num1 << endl;
      return 1;
    }
        
    long long num2 = num*10+9;
    if(num2%in ==0){
      cout << num2 << endl;
      return 1;
    }
    generateNo(num1,in) or  generateNo(num2,in); 
    return -1;
    
}
void generate(long long int & in)
{
    generateNo(9LL,in);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int test =0LL,no =0LL;
    cin >> test;
    for(int i =0;i<test;++i)
    {
        cin >> no;
        generate(no);
        
    }
    return 0;
}
