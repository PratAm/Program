#include<iostream>
#include<cstdlib>
#include <sys/types.h>
#include<unistd.h>
#include<sys/syscall.h>

using namespace std;

void* fun(void *)
{
	int i = 0;
	char buff[100];
	cout <<"thread stack address:" <<static_cast<void*>(&i) <<endl;
 cout <<"thread id :" <<syscall(SYS_gettid) <<endl;
	while(1){
		cout << "enter number:" <<endl;
		char* a = NULL;
//		char* a = (char*)malloc(20);
	cout <<"heap stack address:" <<static_cast<void*>(a) <<endl;
		cin >> buff;
		cout << buff <<endl;
	}
	return NULL;

}

int main(){
 int i =0;
 pthread_t id;
 cout <<"process id :" <<syscall(SYS_gettid) <<endl;
 pthread_create(&id,NULL,fun,0);
	cout <<"Main stack address:"<<static_cast<void*>(&i) <<endl;

	// not calling join on joinable thread caused that thread to become zombie
	pthread_join(id ,NULL);
 return 0 ;
}
