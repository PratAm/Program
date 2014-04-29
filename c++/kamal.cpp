#include<iostream>

using namespace std;

class Demo
{
	int value;
	Demo(const Demo &obj);

	public:
  Demo clone() const
	{
    static Demo obj ;
		obj = new Demo();
		return obj;
	}
};

testfun(const Demo& param)
{
  
}
int main()
{

}
