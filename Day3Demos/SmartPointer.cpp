#include<iostream>
#include<typeinfo.h>
using namespace std;

class Demo
{
	int *p;
public:
	Demo():p(new int(45))
	{
		cout<<"Demo::constr"<<endl;
	}
	~Demo()
	{
		cout<<"Demo::destr"<<endl;
		delete p;
	}
	void disp()
	{
		cout<<*p<<endl;
	}
};

class SmartPointer
{
     Demo *ptr;
public:
	SmartPointer(Demo *p):ptr(p)
	{
		cout<<"SmartPointer::constr"<<endl;
		cout<<"\n*p: "<<typeid(*p).name()<<"\tp: "<<typeid(p).name()<<"\tptr: "<<typeid(ptr).name()<<"\t*ptr: "<<typeid(*ptr).name();

	}

	~SmartPointer()
	{
		cout<<"SmartPointer::destr"<<endl;
		delete ptr;
	}
	

	Demo* getPtr()
	{
		return ptr;
	}

};

int main()
{
	/*
	Demo *d;
	d = new Demo();
	d->disp();
	//delete d;
	*/
	SmartPointer s(new Demo());
	(s.getPtr())->disp();
	return 0;
}
