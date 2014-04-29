#include<iostream>

using namespace std;

class Heap
{
  private:
		int *array;
		bool (*comp)(int,int);
		int heapsize;
	protected:
		int getLeft(int i )
		{
		  return 2*i+1;
		}
		int getRight(int i )
		{
		  return 2*i+2;
		}
		int getParent(int i)
		{
			if(i<=0)
				return -1;
			return (i-1)/2;
		}
		int top(void)
		{
			int max = -1;
			if(heapsize >=0)
				max = array[0];
			return max;
		}
		int size()
		{
			return heapsize+1;
		}
		void heapify(int i)
		{
			int largest = i;
			int left = getLeft(i);
			int right = getRight(i);
			if(left < heapsize and comp(array[i],array[left]))
				largest = left;
			if(right < heapsize and comp(array[largest],array[right]))
				largest = right;

			if(largest != i)
			{
				std::swap(array[i],array[largest]);
				heapify(largest);
			}
		}
		

};
