#include<iostream>
#include<stack>
using namespace std;

bool bracketcheck(string in)
{
	stack<char> Stack;
  char temp ,c;
	int len = in.length();

	for(int i =0;i< len ;i++)
	{
		switch(c = in[i])
		{
			case '{':
			case '[':
			case '(':
				Stack.push(c);
				break;
			case '}':
				 temp = Stack.top();
				 Stack.pop();
				 if(temp != '{')
					 return false;
				  break;
			case ']':
				 temp = Stack.top();
				 Stack.pop();
				 if(temp != '[')
					 return false;
				  break;
			case ')':
				 temp = Stack.top();
				 Stack.pop();
				 if(temp != '(')
					 return false;
				  break;
		}	
	}

	return true;
}


int main()
{
	string in = "(a+[b*c-{d}])";
  cout << bracketcheck(in)<< endl;

	return 0;
}
