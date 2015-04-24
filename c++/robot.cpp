#include<bits/stdc++.h>

using namespace std;

enum direction {
	N = 0,
	W = 1,
	S = 2,
	E = 3
};

direction fromInt(int i ){

	if(i ==0) return N;
	else if (i ==1) return W;
	else if (i ==2) return S;
	else return E;
}


bool isCircular(string in)
{
	int x=0,y=0;
	direction dir = N;

	for (int i =0; i< in.length();++i){

		char move = in.at(i);

		if (move == 'L')
			dir = fromInt((dir+1)%4);
		else if (move == 'R')
			dir = fromInt((dir+4-1)%4);

		else{
			if (dir == N)
				y++;
			else if (dir == W)
				x--;
			else if (dir == S)
				y--;
			else
				x++;
		}
	}

	return (x == 0 and y ==0);

}

int main()
{
	char path[] = "GLGLGLG";
	if (isCircular(path))
		cout << "Given sequence of moves is circular";
	else
		cout << "Given sequence of moves is NOT circular";

	cout <<endl;
}
