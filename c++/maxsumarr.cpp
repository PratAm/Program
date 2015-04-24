#include<stdio.h>

using namespace std;
int ps =0, s=0 ;
int maxSubArraySum(int a[], int size)
{
   int max_so_far = 0, max_ending_here = 0,old =0;
   int i;
   for(i = 0; i < size; i++)
   {
		 old = max_ending_here;
     max_ending_here = max_ending_here + a[i];
		 if(max_ending_here >0 and old <=0)
			 ps =i;
     if(max_ending_here < 0){
        max_ending_here = 0;
		 }
     if(max_so_far < max_ending_here){
        max_so_far = max_ending_here;
				s = ps;
		 }			
    }
    return max_so_far;
} 
 
/*Driver program to test maxSubArraySum*/
int main()
{
   int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   printf("Maximum contiguous sum is %d starting at %d\n", max_sum,s);
   getchar();
   return 0;
}
