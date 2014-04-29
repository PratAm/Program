#include<iostream>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>

	using namespace std;

	int main()

{

	char seq1[] = "ABCDEFGK";

	char seq2[] = "ZGEDFBAP";

	map<char,int> m;

	map<char,int>::iterator iter;

	vector<int> arr;

	int n1,n2;

	n1 = strlen(seq1);

	n2 = strlen(seq2);


	for(int i = 0;i<n1;i++)

		m[seq1[i]] = i;

	int count =0,window = 0, maxwindow = 0;

	for(int i=0;i<n2;i++)

	{

		iter = m.find(seq2[i]);

		if(iter!= m.end())
		{
			count++;
			arr.push_back(iter->second);
		}

		if(count > 0 && (iter==m.end() || i==n2-1))
		{
			window = 1;

			if(count >1)
			{
				sort(arr.begin(),arr.end());

				//check if the characters in SEQ1 lie in the window of size = count

				for(int j=1;j<count;j++)

				{
					if(arr[j]-arr[j-1]==1) 
						window ++;
					else
					{
						window = 1;
					}

					if (window > maxwindow) 
						maxwindow = window;

				}

			}
			else 
				 maxwindow = 1;

			count =0;
			arr.empty();

		}

	}

	cout<<"Window of max size is "<<maxwindow;

	return 0;

}
