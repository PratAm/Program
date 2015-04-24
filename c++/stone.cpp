#include<iostream>
#include<vector>
#include<set>

using namespace std;
vector<int> list;
set<int> result;

void printResult(){
    
    for(std::set<int>::iterator it=result.begin();it!=result.end();++it){
        cout << *it <<" ";
    }
}

void getLastNum(vector<int> &param,int N){
   if(list.size()==N){
       result.insert(list[list.size()-1]);
       return;
   }
   for(int i=0;i<param.size();++i){
       list.push_back(param[i]+list[list.size()-1]);
       getLastNum(param,N);
       list.pop_back();
   }
                  
    
}
int main(){
    int T = 0;
    int a=0,b=0,N=0;
  
    cin >> T;
    while(T--){
          vector<int> param;
        cin >>N;
        cin >>a;
        param.push_back(a);
        cin >>b;
        param.push_back(b);
        
        list.clear();
        result.clear();
   			list.push_back(0);
        getLastNum(param,N);
        
        printResult();
    }
    return 0;
}
