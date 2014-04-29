#include<iostream>
using namespace std;
int &fun() {
  static int a = 10;
  return a;
}
 
int main() {
  int &y = fun();
//	int y = fun();
  y = y +30;
  cout<<fun()<<endl;
//	cout<<y<<endl;
  return 0;
}
