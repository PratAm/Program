#include<iostream>

using namespace std;

void strip(string &str)
{
	int i=0,j=0;
	char c;

	int size = str.size();

	for(; i< size and  str[i]!='\0' ;)
	{
/*    uncomment code to remove ac even in the output
  if (j>1 && str[j-2] == 'a' && str[j-1] =='c')
     j = j-2;
*/
    if(str[i] != 'b' and str[i] != 'a')
		{
			str[j++] = str[i++];
			
		}else if(str[i] == 'b')
		{
			i++;
		}else 
		{
			if(str[i+1] == 'c')
		  {
        i=i+2;
			}else
			{
				str[j++]= str[i++];
				
			}
		}
	}
	str.resize(j-1);

	return ;
}

int main()
{
  string str("ambmacdacb");
	cout << "i/p :" << str << endl;
	strip(str);
	cout << "o/p :" << str << endl;
	cout << "o/p size:" << str.size() << endl;
	return 0;
}
