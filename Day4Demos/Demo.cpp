#include<iostream>
using namespace std;
class A
{
public:
	virtual void set()
	{
		cout<<"A::set"<<endl;
		//get();
	}
	virtual void get()
	{
		cout<<"A::get"<<endl;
	}
};

class B :public A
{
public:
	virtual void get()
	{
		cout<<"B::get"<<endl;
	}
};
class C : public B
{
	public:
	virtual void get()
	{
		cout<<"C::get"<<endl;
	}

};

void main()
{
	A *p = new C();
    p->get();

}







