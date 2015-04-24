#include<iostream>
#include<set>
#include<vector>
#include<cstring>

using namespace std;



int main(){
    int N =0;
    int hash[26];
    
    std::vector<string> stringSet;
    std::set<char> line;
    
    cin >>N;
		std::fill_n(hash, 26, N);
   
    
    while(N--){
        string temp;
        cin >> temp;
        stringSet.push_back(temp);
    }
    
    for(int i =0;i < stringSet[0].size();++i){
        line.insert(stringSet[0][i]);
    }
    for(std::set<char>::iterator it = line.begin();it!=line.end();++it){
            hash[*it-'a'] -= 1; 
    }
    
    for(int i =1;i <stringSet.size();++i){
        line.clear();
        for(int j = 0;j <stringSet[i].size();++j){
            line.insert(stringSet[i][j]);   
        }
        for(std::set<char>::iterator it = line.begin();it!=line.end();++it){
            hash[*it-'a'] -= 1; 
        }
    }
    
    int result =0;
    for(int i =0;i <26;++i){
        if(hash[i] == 0)
            result++;
    }
    cout<<result<<endl;
    return 0;
}
