#include<iostream>
using namespace std;

class Demo
{
	int i;
public:
	Demo() :i(1)
	{
		cout << "constr" << endl;
	}

	~Demo()
	{
		cout << "destr" << endl;
	}
}d;

int main()
{
	cout << "main" << endl;
	return 0;
}
