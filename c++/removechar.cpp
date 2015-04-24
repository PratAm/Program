#include<iostream>

using namespace std;

class RemoveChar{
	public:
		string in;
		string rem;
		bool *flag;
		RemoveChar(string in, string re):in(in),rem(re){
		 flag = new bool[26];
		}

		void remove();
};

void RemoveChar::remove(){

 for(int i =0;i< rem.length();++i){
  flag[rem[i]-'a'] = true; 
 }
 int write = 0;
 for(int i =0;i<in.length();++i){
  if(not flag[in[i]-'a'])
   in[write++]= in[i];
 }
 in.erase(write); // will earse to last element.
}

int main(){

	RemoveChar ob("amar pratap singh","ma");
  ob.remove();
	cout << ob.in << endl;
	return 0;
}
