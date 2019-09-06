#include<iostream>
using namespace std;

class Demo
{
	int i;
public:
	Demo() :i(12)
	{
		this->Demo(23);
	}

	~Demo()
	{
		cout << "destr" << endl;
	}
	Demo(int a) :i(a)
	{
		cout << "par" << endl;
	}

	void disp()
	{
		cout <<i << endl;
	}
};

int main()
{
	Demo d;
	d.disp();

	
	return 0;
}
