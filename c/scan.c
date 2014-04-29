#include<stdio.h>

int main(int argc, char **argv)
{
 int a;
 char b[10];
 char *format = "   %d%s   ";
 scanf("   %d         %s",&a,b);

 int z = printf(format,a,b);

 printf("printf result :%d\n",z);

 printf("argv[0]: %s\n",argv[0]);
}
