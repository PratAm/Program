#include <iostream>
#include <string>
using namespace std;
int main ()
{
  std::string str ("This is an example sentence.");
  std::cout << str << " " << str.size() <<'\n';
                                           // "This is an example sentence."
  str.erase (10,8);                        //            ^^^^^^^^
  std::cout << str << " " << str.size() <<'\n';
                                           // "This is an sentence."
  str.erase (str.begin()+9);               //           ^
  std::cout << str << " " << str.size() <<'\n';
                                           // "This is a sentence."
  str.erase (str.begin()+5, str.end()-9);  //       ^^^^^
  std::cout << str <<" " << str.size() << '\n';
                                           // "This sentence."
  return 0;
}
