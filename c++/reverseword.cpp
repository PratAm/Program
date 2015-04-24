
#include<iostream>
#include<algorithm>
using namespace std;

class ReverseWord{
	public:
		string in;
		ReverseWord(string in):in(in){}

		void reverse();
};

void ReverseWord::reverse(){

 int start = 0,end =0;

 std::reverse(in.begin(),in.end());
 while(end < in.length())
 {
  if( in[end] != ' ' )
	{
	  start = end;
		while(end < in.length() and in[end] !=' ')
			end++;
    std::reverse(in.begin()+start, in.begin()+end);
	}else
		end++;
  }
}

int main(){

	ReverseWord ob("amar pratap singh");
  ob.reverse();
	cout << ob.in << endl;
	return 0;
}
