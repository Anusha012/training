#include<iostream>
using namespace std;
class Demo;
class Demo1
{
public:
	void set(Demo &d);
	void disp(const Demo &d);
};


class Demo
{
	int i;
public:
	Demo():i(34)
	{}
	friend void Demo1::disp(const Demo &d);

};

void Demo1::set(Demo &d)
{
	d.i=55;
}

void Demo1::disp(const Demo &d)
{
	cout<<d.i<<endl;
}


void main()
{
	Demo d;
	Demo1 d1;
	d1.set(d);
	d1.disp(d);
}