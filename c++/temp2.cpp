#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int generateNo(vector<long long> &data, long long num)
{
    queue<long long> temp;
    temp.push(num);
    
    while(not temp.empty())
    {
        if(temp.front() > LLONG_MAX/2)
          return -1;
        long long num1 = temp.front();
        data.push_back(num1);
        temp.pop();
        temp.push(num1*10);
        temp.push(num1*10+9);
    }
}
void generate(vector<long long> &data)
{
    generateNo(data,9LL);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int test =0LL,no =0LL;
    cin >> test;
    vector<long long> data;
    generate(data);
    for(int i =0;i<test;++i)
    {
        cin >> no;
        for(int i =0 ;i < data.size();++i)
        {
            if(data[i]%no ==0)
                cout << data[i] << endl;
                break;
        }
        
    }
    return 0;
}
