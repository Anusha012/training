#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "C" << endl; }
	~A() { cout << "D" << endl; }
	void f(A x)
	{
		A y;
		cout << "f" << endl;
	}
};

int main()
{
	A y;
	y.f(y);
	return 0;
}

