#include<iostream>
using namespace std;

static int row = 1;

class permutate{
	public:	
		string in;
		string out;
		unsigned int length;
		bool *used;

		permutate(string in):in(in){
			length = in.length();
			used = new bool[length];
		}
		void permute();
};

void permutate::permute(){
	if(out.length() == length){
		cout <<row <<":" <<out << endl;
		row++;
	}

	for(unsigned int i =0; i<length;++i){
		if(used[i]) continue;
		out += in[i];
		used[i]= true;
		permute();
		used[i]= false;
		int l = out.length();
		out = out.substr(0,l-1);
	}
}

int main(){

	permutate p("abcd");
	p.permute();
	return 0;

}
