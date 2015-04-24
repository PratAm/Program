#include<iostream>
#include<map>

using namespace std;


void ordergroup(int *arr,int size){

	std::map<int,int> occ;

	for (int i =0;i < size;++i){
		if (occ.count(arr[i]) ==0) {
			occ[arr[i]] = 1;
		}else{
			occ[arr[i]]++;
		}
	}

	for (int i =0;i < size;++i){

		if (occ.count(arr[i])){
		  int count = occ[arr[i]];
		  for(int j =0; j< count ;++j)
			  cout << arr[i] <<" " ;
			occ.erase(arr[i]);
		}
	}
		cout << endl;
}

int main ()
{
	int arr[] = {10, 5, 3, 10, 10, 4, 1, 3};
	int size = sizeof(arr)/sizeof(arr[0]);
	ordergroup(arr,size);


	return 0;
}
