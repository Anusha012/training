#include<iostream>
using namespace std;
class A
{
	int i;
	int j;
public:
	A() :i(10), j(11)
	{ }
	void  fun()
	{
		this++;
		cout << this->j;

	}
};

int main()
{
	A a;
	a.fun();
	return 0;
}

