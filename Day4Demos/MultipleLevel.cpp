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

class B
{
	protected:
	int i;
public:
	B():i(2)
	{}
};
class C : public A,public B
{
	//int i;
public:
	C()//:i(3)
	{}

	void disp()
	{
		cout<<A::i<<endl;
	}
};


void main()
{
	C c1;
	c1.disp();
}
