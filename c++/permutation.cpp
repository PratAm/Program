#include <iostream>
#include <string>
 
using namespace std;
 
void permute(string str, int sindex, int eindex)
{
    if (sindex == eindex)
        cout << str <<"\n";
    for (int i = sindex; i <= eindex; i++){
        swap(str[sindex], str[i]);
        permute(str, sindex+1, eindex);
        swap(str[sindex], str[i]);
    }
}
 
int main(void)
{
    string s = "ABCD";
    permute(s, 0, 3);
    return 0;
}
