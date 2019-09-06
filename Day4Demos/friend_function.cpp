#include<iostream>
using namespace std;
class Demo
{
	int i;
public:
	Demo():i(34)
	{}
	friend void disp(const Demo &d);
};

void disp(const Demo &d)
{
	cout<<d.i<<endl;
}

void main()
{
	Demo d;
	disp(d);
}