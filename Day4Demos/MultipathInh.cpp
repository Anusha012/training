#include<iostream>
using namespace std;

class A
{
protected:
	int i;
public:
	A():i(1)
	{
		cout<<"A"<<endl;
	}
};

class B:public virtual A
{
	
public:
	B()
	{
		cout<<"B"<<endl;
	}
};
class C:virtual public A
{
	
public:
	C()
	{
		cout<<"C"<<endl;
	}
};

class D:public B , public C
{
	
public:
	D():A()
	{
		cout<<"D"<<endl;
	}
	void disp()
	{
		cout<<C::i<<endl;
	}
};

void main()
{
	D c1;
	c1.disp();
	cout<<sizeof(c1)<<endl;
}


#data			without_virtual			with_virtual
1					8								12
2					16								16
3					24								20