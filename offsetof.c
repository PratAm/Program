#include <stdio.h>
 
#define FUN(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))
 
typedef struct PodTag
{
   char    i;
   double  d;
   char    c;
} PodType;
 
int main()
{
   printf("%d", FUN(PodType, c) );
    
   getchar();
   return 0;
}

