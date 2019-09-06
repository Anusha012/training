#include<iostream>
using namespace std;

class A
{
	int a;
public:
	A(int a)
	{
		this->a = a;
	}
	void disp()
	{
		cout << a << endl;
	}
};

int main()
{
	A a1(3);
	a1.disp();
	return 0;
}
