#include<iostream>
using namespace std;

class A
{
protected:
	int i;
public:
	A():i(1)
	{}
};

class B:public A
{
	protected:
	//int i;
public:
	//B()//:i(2),A()
	//{}
};
class C :public B
{
	//int i;
public:
	C():A()
	{}

	void disp()
	{
		cout<<i<<endl;
	}
};


void main()
{
	C c1;
	c1.disp();
}
